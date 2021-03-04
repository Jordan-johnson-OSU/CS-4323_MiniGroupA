/*
 * header.h
 *
 */

#ifndef SRC_HEADER_H_
#define SRC_HEADER_H_

struct Employee {
	int id;
	char **employeeName;
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

struct Salary {
	int id;
	char **jobTitle;
	float basePay;
	float overtimePay;
	float benefit;
	char **status;
};

struct historyData {
	int id;
	char **employeeName;
	char **jobTitle;
	float basePay;
	float overtimePay;
	float benefit;
	char **status;
	float satisfaction_level;
	int number_project;
	int average_monthly_hours;
	int time_spend_company_in_yrs;
	int work_accident;
	int promotion_last_5years;
};

#endif /* SRC_HEADER_H_ */
