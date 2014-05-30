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
	struct STUDENT * start = &(student[0]), *cur,*pre;
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
	for (i = 0,cur=start,pre=0; i < 9; i++,cur=start,pre=0) {
		for(j=0;j<9-i;j++){
			if(cur->cool<cur->next->cool){
				if(pre){
					pre->next=cur->next;
					cur->next=pre->next->next;
					pre->next->next=cur;
					pre=pre->next;
				}
				else{
					start=cur->next;
					cur->next=start->next;
					start->next=cur;
					pre=start;
				}
			}
			else{
				pre=cur;
				cur=cur->next;
			}
		}
	}
	cur = start;
	for(i=0 ; cur->next ; i++){
		printf("%d등\n",i+1);
		while(cur->next){
			printf("%-10s %d점\n",cur->name,cur->cool);
			if(cur->cool==cur->next->cool){
				cur=cur->next;
				i++;
				continue;
			}
			else{
				cur=cur->next;
				break;
			}
		}
		printf("\n");

	}

	return 0;
}
