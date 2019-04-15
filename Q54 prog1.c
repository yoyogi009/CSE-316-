#include<stdio.h>
#include<unistd.h>
struct resource{

	int pen;
	int paper;
	int q_paper;
	int allot_id;

};
struct t_resource{

	int pen_count ;
	int paper_count ;
	int q_paper_count ;
};

struct t_resource t[3];

void allotment(struct resource a){
	if(a.allot_id == 0){
		a.pen=1;
	}
	else if(a.allot_id == 1){
		a.paper=1;
	}
	else if(a.allot_id == 2){
		a.q_paper=1;
	}

}


int main(){
	struct resource s[3];

	int i,j,count=0;
	for(i=0;i<3;i++){
		s[i].allot_id=i;
		allotment(s[i]);
	}

	printf("\nResources alloted are                          :");
	for(i=0;i<3;i++){
		if(s[i].pen == 1)
		printf("\nResources alloted to student %d are        : pen ",i+1);

		if(s[i].paper)
		printf("\nResources alloted to student %d are        : paper ",i);

		if(s[i].q_paper == 1)
		printf("\nResources alloted to student %d are        : question paper ",i+1);
	}

	while(count != 3){
		for(i=0;i<3;i++){
			if(i=0){
				t[i].paper_count=1;
				t[i].pen_count=1;
				for(j=0;j<3;j++){
					if(s[j].q_paper==1){
						printf("\nStudent %d has completed his job !",j+1);
						count++;
					}
				}
			}

			if(i=1){
				t[i].q_paper_count=1;
				t[i].pen_count=1;
				for(j=0;j<3;j++){
					if(s[j].paper==1){
						printf("\nStudent %d has completed his job !",j+1);
						count++;
					}
				}
			}

			if(i=2){
				t[i].paper_count=1;
				t[i].q_paper_count=1;
				for(j=0;j<3;j++){
					if(s[j].pen==1){
						printf("\nStudent %d has completed his job !",j+1);
						count++;
					}
				}
			}
		}

	}
	return 0;

}
