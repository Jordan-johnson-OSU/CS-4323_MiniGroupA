/*
 * header.h
 *
 */

#ifndef SRC_HEADER_H_
#define SRC_HEADER_H_

struct Employee {
	int id;
	char *employeeName;
};

struct EmployeeList {
	int employeeCount;
	struct Employee *employees;
};

struct SatisfactionLevel {
	int id;
	float satisfaction_level;
	int number_project;
	int average_monthly_hours;
	int time_spend_company_in_yrs;
	int work_accident;
	int promotion_last_5years;
};

struct SatisfactionLevelList {
	int satisfactionLevelCount;
	struct SatisfactionLevel *satisfactionLevels;
};

struct Salary {
	int id;
	char *jobTitle;
	float basePay;
	float overtimePay;
	float benefit;
	char *status;
};

struct SalaryList {
	int salarycount;
	struct Salary *salaries;
};


struct historyData {
	int id;
	char *employeeName;
	char *jobTitle;
	float basePay;
	float overtimePay;
	float benefit;
	char *status;
	float satisfaction_level;
	int number_project;
	int average_monthly_hours;
	int time_spend_company_in_yrs;
	int work_accident;
	int promotion_last_5years;
};

struct inputFiles {
	char *employeeFile;
	char *satisfactionFile;
	char *salaryFile;
};

struct EmployeeList* loadEmployees(char *nameFile);

void *serverInit(void *files);

void *clientManagerInit();

#endif /* SRC_HEADER_H_ */
