#pragma once
#ifndef PATIENT_H
#define PATIENT_H

#define PATIENT_NAME_LEN 50
#define PATIENT_GENDER_LEN 10 
#define PATIENT_DIAGNOSIS_LEN 100
#define PATIENT_PHONE_LEN 20

typedef struct Patient {
	int patientId;
	char name[PATIENT_NAME_LEN];
	char gender[PATIENT_GENDER_LEN];
	int age;
	char diagnosis[PATIENT_DIAGNOSIS_LEN];
	char phone[PATIENT_PHONE_LEN];
	struct Patient* next;
	//医疗记录还没写
	//还有科室 大夫
} Patient;
extern Patient* patientListHead; // 病人链表头指针

void initPatientList();
void addPatient(Patient* patientListHead);
int deletePatientById(int patientId); //返回类型int是为了确认删除状态
Patient* searchPatientById(int patientId);
Patient* searchPatientByName(char* patientName);
void modifyPatient(Patient* patient);
void printAllPatients();
 
#endif
