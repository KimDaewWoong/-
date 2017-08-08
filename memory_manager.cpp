#include<cstdio>
#include<cstring>

//struct

struct FRAME {
	bool valid;
	int virtual_address;
};

struct PAGE {
	int frame_num;
	bool valid;
};

struct TLB {
	int page_num;
	int frame_num;
	bool valid;
};
//init
FRAME re_frame[128];
PAGE re_page[256];
TLB re_tlb[16];
int page[128], page_idx;
int tlb[16], tlb_idx;
char Physical_M[128 * 256];
int PAGE_HIT, TLB_HIT;

//file open
FILE *FILE_address;
FILE *FIFO_address;
FILE *FILE_Frame_table = fopen("LRU_Frame_table.txt", "wt");
FILE *FILE_Physical = fopen("LRU_Physical.txt", "wt");
FILE *FILE_Physical_mem = fopen("LRU_Physical_Memory.bin", "wb");
FILE *Backing_store = fopen("BACKING_STORE.bin", "rb");
FILE *FIFO_Frame_table = fopen("FIFO_Frame_table.txt", "wt");
FILE *FIFO_Physical = fopen("FIFO_Physical.txt", "wt");
FILE *FIFO_Physical_mem = fopen("FIFO_Physical_Memory.bin", "wb");

//function
void func(int, bool);
void TLB_update(int);
void TLB_victim_update(int, int);
void empty_TLB(int);
void PAGE_table_update(int);
void PAGE_victim_update(int, int);

//main
int main(int argc, char *argv[]) {
	FILE_address = fopen(argv[1], "r");
	int address = 0, in_cnt = 0;
	while (fscanf(FILE_address, "%d", &address) != EOF) {
		in_cnt++;
		//LRU
		func(address, true);
	}
	for (int i = 0; i < 128; i++)
	{
		fprintf(FILE_Frame_table, "%d %d %d\n", i + 1, re_frame[i].valid, re_frame[i].virtual_address);
	}

	for (int i = 0; i < 128 * 256; i++)
	{
		fwrite(&Physical_M[i], 1, 1, FILE_Physical_mem);
	}
	printf("TLB hit ratio : ( %d ) hit out of ( %d )\n", TLB_HIT, in_cnt);
	printf("LRU hit ratio : ( %d ) hit out of ( %d )\n", PAGE_HIT, in_cnt);
	fclose(FILE_Frame_table);
	fclose(FILE_Physical);
	fclose(FILE_Physical_mem);
	fclose(FILE_address);

	////////////////////////////////////////////////////////////////////////////////////////////////////

	FIFO_address = fopen(argv[1], "r");

	memset(re_frame, 0, sizeof(re_frame));
	memset(re_page, 0, sizeof(re_page));
	memset(re_tlb, 0, sizeof(re_tlb));
	memset(page, 0, sizeof(page));
	memset(tlb, 0, sizeof(tlb));
	memset(Physical_M, 0, sizeof(Physical_M));

	address = 0, in_cnt = 0;
	page_idx = tlb_idx = 0;
	TLB_HIT = PAGE_HIT = 0;
	while (fscanf(FIFO_address, "%d", &address) != EOF) {
		in_cnt++;
		//FIFO
		func(address, false);
	}

	for (int i = 0; i < 128; i++)
	{
		fprintf(FIFO_Frame_table, "%d %d %d\n", i + 1, re_frame[i].valid, re_frame[i].virtual_address);
	}

	for (int i = 0; i < 128 * 256; i++)
	{
		fwrite(&Physical_M[i], 1, 1, FIFO_Physical_mem);
	}

	printf("TLB hit ratio : ( %d ) hit out of ( %d )\n", TLB_HIT, in_cnt);
	printf("FIFO hit ratio : ( %d ) hit out of ( %d )\n", PAGE_HIT, in_cnt);

	fclose(Backing_store);
	fclose(FIFO_address);
	fclose(FIFO_Frame_table);
	fclose(FIFO_Physical);
	fclose(FIFO_Physical_mem);
	return 0;

}

//TLB update 함수
void TLB_update(int page_num) {
	for (int i = 0; i < tlb_idx; i++) {
		if (tlb[i] == page_num) {
			for (int j = i; j < tlb_idx - 1; j++) {
				tlb[j] = tlb[j + 1];
			}
			tlb[tlb_idx - 1] = page_num;
			return;
		}
	}
}

//TLB의 victim을 선택 and update함수

void TLB_victim_update(int victim, int page_num) {
	for (int i = 0; i < tlb_idx - 1; i++) {
		tlb[i] = tlb[i + 1];
	}

	tlb[tlb_idx - 1] = victim;
	re_tlb[victim].page_num = page_num;
	re_tlb[victim].frame_num = re_page[page_num].frame_num;
}

//TLB가 비어있을 경우 빈 TLB자리를 할당하는 함수
void empty_TLB(int page_num) {
	for (int i = 0; i < 16; i++) {
		if (!re_tlb[i].valid) {
			re_tlb[i].valid = true;
			re_tlb[i].page_num = page_num;
			re_tlb[i].frame_num = re_page[page_num].frame_num;
			tlb[tlb_idx++] = i;
			return;
		}
	}
}

//Page table update 함수
void PAGE_table_update(int page_num) {
	for (int i = 0; i < page_idx; i++) {
		if (page[i] == page_num) {
			for (int j = i; j < page_idx - 1; j++) {
				page[j] = page[j + 1];
			}
			page[page_idx - 1] = page_num;
			return;
		}
	}
}

//Page table이 꽉찾을경우 victim을 선택 and update하는 함수
void PAGE_victim_update(int victim, int page_num) {
	for (int i = 0; i < 127; i++) {
		page[i] = page[i + 1];
	}
	page[page_idx - 1] = page_num;
	re_page[page_num].valid = true;
	re_page[page_num].frame_num = re_page[victim].frame_num;
	re_page[victim].valid = false;
	re_page[victim].frame_num = 0;
}

//알고리즘 실행 함수
void func(int Vaddress, bool algo) {
	//page_num, offset
	int page_num = Vaddress / 256;
	int offset = Vaddress % 256;
	bool TLB_valid = false;

	//TLB cehck
	for (int i = 0; i < 16; i++) {
		if (re_tlb[i].page_num == page_num && re_tlb[i].valid) {
			if (algo) fprintf(FILE_Physical, "Virtual address: %d Physical address: %d\n", Vaddress, (re_tlb[i].frame_num * 256) + offset);
			else fprintf(FIFO_Physical, "Virtual address: %d Physical address: %d\n", Vaddress, (re_tlb[i].frame_num * 256) + offset);

			TLB_HIT++;
			TLB_valid = true;
			TLB_update(i);
			//Page Table update(LRU)
			if (algo) PAGE_table_update(page_num);
			break;
		}
	}

	//TLB에 없을경우
	if (!TLB_valid) {
		//Page에 있는경우
		if (re_page[page_num].valid) {
			if (algo) fprintf(FILE_Physical, "Virtual address: %d Physical address: %d\n", Vaddress, (re_page[page_num].frame_num * 256) + offset);
			else fprintf(FIFO_Physical, "Virtual address: %d Physical address: %d\n", Vaddress, (re_page[page_num].frame_num * 256) + offset);
			PAGE_HIT++;
			//Page Table update(LRU)
			if (algo) PAGE_table_update(page_num);
			//TLB가 꽉찬경우
			if (tlb_idx == 16) {
				TLB_victim_update(tlb[0], page_num);
			}
			//빈 TLB가 있는경우
			else {
				empty_TLB(page_num);
			}
		}

		//Page에 없는경우
		//Backing Store에서 찾는다.
		else {
			char back[256];
			fseek(Backing_store, (page_num * 256), SEEK_SET);
			fread(back, 1, 256, Backing_store);
			//Page가 꽉찬경우
			if (page_idx == 128) {
				int victim = page[0];
				PAGE_victim_update(victim, page_num);
				re_frame[re_page[page_num].frame_num].virtual_address = Vaddress;
				TLB_valid = false;
				//victim이 TLB에 올라와 있는 경우도 있으니 TLB update
				for (int i = 0; i < 16; i++) {
					if (re_tlb[i].page_num == victim && re_tlb[i].valid) {
						TLB_valid = true;
						re_tlb[i].page_num = page_num;
						TLB_update(i);
					}
				}
				if (!TLB_valid) {
					//TLB가 꽉찬경우
					if (tlb_idx == 16) {
						TLB_victim_update(tlb[0], page_num);
					}
					//빈 TLB가 있는경우
					else {
						empty_TLB(page_num);
					}
				}
				if (algo) fprintf(FILE_Physical, "Virtual address: %d Physical address: %d\n", Vaddress, (re_page[page_num].frame_num * 256) + offset);
				else fprintf(FIFO_Physical, "Virtual address: %d Physical address: %d\n", Vaddress, (re_page[page_num].frame_num * 256) + offset);
			}

			//Page table이 비어있는 경우
			else {
				//빈 프레임 할당
				for (int i = 0; i < 128; i++) {
					if (!re_frame[i].valid) {
						re_frame[i].valid = true;
						re_frame[i].virtual_address = Vaddress;
						re_page[page_num].valid = true;
						re_page[page_num].frame_num = i;
						page[page_idx++] = page_num;
						if (algo) fprintf(FILE_Physical, "Virtual address: %d Physical address: %d\n", Vaddress, (i * 256) + offset);
						else  fprintf(FIFO_Physical, "Virtual address: %d Physical address: %d\n", Vaddress, (i * 256) + offset);
						//TLB도 update해준다.
						if (tlb_idx == 16) {
							TLB_victim_update(tlb[0], page_num);
						}
						else {
							empty_TLB(page_num);
						}
						break;
					}
				}
			}
			//backing stroe에서 가져온 파일 저장
			for (int i = 0; i < 256; i++) {
				Physical_M[re_page[page_num].frame_num * 256 + i] = back[i];
			}
		}
	}
}