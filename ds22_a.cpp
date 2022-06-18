#include <stdio.h>
#include <stdlib.h>

int count = 0;

void divisionkey(int key, int bucket, int slot, int** tableset) {
	int identifier = key % bucket;
	while (count < bucket * slot) {
		for (int slotnumber = 0; slotnumber < slot; slotnumber++) {
			if (tableset[identifier][slotnumber] == -1) {
				tableset[identifier][slotnumber] = key;
				count++;
				return;
			}
		}
		if (identifier == bucket - 1)
			identifier = 0;
		else
			identifier++;
	}
}

int searchkey(int value, int bucket, int slot, int** tableset) {
	int identifier = value % bucket;
	int searchcount = 0;
	while (searchcount < bucket * slot) {
		for (int slotnumber = 0; slotnumber < slot; slotnumber++) {
			if (tableset[identifier][slotnumber] == value)
				return identifier;
			else
				searchcount++;
		}
		if (identifier == bucket - 1)
			identifier = 0;
		else
			identifier++;
	}
	return -1;
}

int main() {

	FILE* hashnumber;

	fopen_s(&hashnumber, "in.txt", "r");
	int bucketsize, slotsize;
	fscanf_s(hashnumber, "%d", &bucketsize);
	fscanf_s(hashnumber, "%d", &slotsize);
	int** hashtable = (int**)malloc(sizeof(*hashtable) * bucketsize);
	for (int i = 0; i < bucketsize; i++) {
		hashtable[i] = (int*)malloc(sizeof(**hashtable) * slotsize);
		for (int j = 0; j < slotsize; j++)
			hashtable[i][j] = -1;
	}
	int keynumber;
	while (!feof(hashnumber)) {
		fscanf_s(hashnumber, "%d", &keynumber);
		divisionkey(keynumber, bucketsize, slotsize, hashtable);
	}
	fclose(hashnumber);

	printf("Hash Table\n");
	for (int hash = 0; hash < bucketsize; hash++) {
		printf("%d: ", hash);
		for (int slot = 0; slot < slotsize; slot++) {
			if (hashtable[hash][slot] != -1)
				printf("%d ", hashtable[hash][slot]);
		}
		printf("\n");
	}

	printf("key 검색 : ");
	scanf_s("%d", &keynumber);
	while (keynumber != -999) {
		printf("%d\n", searchkey(keynumber, bucketsize, slotsize, hashtable));
		printf("key 검색 : ");
		scanf_s("%d", &keynumber);
	}

	return 0;

}