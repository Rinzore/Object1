#pragma once
#ifndef WARD_H
#define WARD_H

#define WARD_TYPE_LEN 20

typedef struct Ward {
	int wardId;
	char typeOfWard[WARD_TYPE_LEN];
	int totalBedOfWard;
	int availableBedOfWard;
	struct Ward* next;
} Ward;

extern Ward* wardListHead; // 病房链表头指针

void initWardList();
void addWard(Ward* wardListHead);
int deleteWardById(int wardId); //返回类型int是为了确认删除状态
Ward* searchWardById(int wardId);
void modifyWard(Ward* ward);
void printAllWards();

#endif
