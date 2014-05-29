/* Project : cool_student
 * cool_student.c
 *
 *  Created on: 2014. 5. 28.
 *      Author: Jung Sangwoo  contact : holyavarice@gmail.com
 */

#include <stdio.h>

int main() {
	int i,j;
	struct STUDENT {
		char name[10];
		int cool;
		struct STUDENT * next;
	} student[10];
	struct STUDENT * start = &(student[0]), *cur, *tmp;
	for (i = 0; i < 9; i++) {
		student[i].next = &student[i + 1];
	}

	student[9].next = 0;
	for (i = 0; i < 10; i++) {
		printf("%d번째 학생의 이름 : ", i + 1);
		scanf("%s", student[i].name);
		printf("%d번째 학생의 쿨점수 : ", i + 1);
		scanf("%d", &student[i].cool);
	}
	for (i = 0; i < 9; i++) {
		cur = start;
		while (cur->next->next) {
			if (cur == start) {
				if (cur->cool < cur->next->cool) {
					start = cur->next;
					cur->next = start->next;
					start->next = cur;
					cur=start;
				}
			}

			if (cur->next->cool < cur->next->next->cool) {
				tmp = cur->next->next;
				cur->next->next = cur->next->next->next;
				tmp->next = cur->next;
				cur->next = tmp;
			}
			cur = cur->next;

		}
	}//
	cur = start;
	while(cur){
		printf("%s\t%d\n",cur->name,cur->cool);
		cur=cur->next;
	}

	return 0;
}
