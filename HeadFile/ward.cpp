#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ward.h"

void initWardList() {
	wardListHead = NULL;
}//初始化病房头指针为NULL

void addWard(Ward* p) {					//尾插法添加病房
	if (p == NULL) return;
	p->next = NULL;
	if (wardListHead == NULL) 
	{
		wardListHead = p;
	}
	else
	{
		Ward* current = wardListHead;
		while (current->next != NULL) current = current->next;
		current->next = p;
	}	
}

int deleteWardById(int wardId) {        //双指针法删除病房
	if (wardListHead == NULL) return -1;//病房列表为空，无法删除
	Ward* current = wardListHead;
	Ward* previous = NULL;
	while (current != NULL) {
		if (current->wardId == wardId) {
			if (previous == NULL) {     //特判删除首位置病房
				wardListHead = current->next;
			}else {
				previous->next = current->next;
			}
			free(current);
			return 1;	//成功删除病房
		}
		previous = current;
		current = current->next;	
	}
	return 0;//未找到病房
}

Ward* searchWardById(int wardId) {		//线性搜索病房
	if (wardListHead == NULL) return NULL ;//病房列表为空，无法搜索
	Ward* current = wardListHead;
	while (current != NULL) {
		if (current->wardId == wardId) return current->next;//成功找到病房

		current = current->next;
	}
	return 0;//未找到病房
}

void modifyWard(Ward* ward) {			//修改病房信息
	if (wardListHead == NULL) return ;//病房列表为空，无法修改
	Ward* target = searchWardById(ward->wardId);
	if (target == NULL) return ;//未找到病房，无法修改
	target->wardId = ward->wardId;
	strcpy(target->typeOfWard, ward->typeOfWard);
	target->totalBedOfWard=ward->totalBedOfWard;
	target->availableBedOfWard = ward->availableBedOfWard;
}
			
void printAllWards() {		//
	if (wardListHead == NULL) return; //病房为空，无效访问
	Ward* current = wardListHead;
	while (current != NULL) {
			printf("%d\n%s\n%d\n%d\n", current->wardId,current->typeOfWard, current->totalBedOfWard, current->availableBedOfWard);
	}
}
