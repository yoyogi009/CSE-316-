#include<stdio.h>

int main()

{



    int process[5],starttime[5],arrivaltime[5],bursttime[5],waitingtime[5],turnartime[5],noofprocess,total=0,pos,temp;

	float waitingtimeavg,turnartimeavg,priority[5];

	int i,j;

    printf("enter number of process to run :  ");

    scanf("%d",&noofprocess);

    printf("\nenter arrival time , burst time and start time for each and every process");


    for(i=0;i<noofprocess;i++)

    {

        printf("\nP[%d]\n",i+1);

        printf("Start time : ");

        scanf("%d",&starttime[i]);

        printf("Arrival time:");

        scanf("%d",&arrivaltime[i]);

        printf("Burst Time:");

        scanf("%d",&bursttime[i]);

        process[i]=i+1;

    }







    waitingtime[0]=0;




    for(i=1;i<noofprocess;i++)

    {

        waitingtime[i]=0;

        for(j=0;j<i;j++)

            waitingtime[i]=starttime[j]-arrivaltime[j];



        total=total+waitingtime[i];

    }



     for(i=0;i<noofprocess;i++)

    {

    	priority[i]=1+waitingtime[i]/bursttime[i];

    }



    waitingtimeavg=total/noofprocess;

    total=0;



    printf("\nProcess\t    Burst Time    \tpriority \tWaiting Time\tTurnaround Time");

    for(i=0;i<noofprocess;i++)

    {

        turnartime[i]=bursttime[i]+waitingtime[i];

        total=total+turnartime[i];

        printf("\nP[%d]\t\t  %d\t\t  %d\t\t  %d\t\t  %d",process[i],bursttime[i],priority[i],waitingtime[i],turnartime[i]);

    }



    turnartimeavg=total/noofprocess;

    printf("\n\nAverage Waiting Time=%f",waitingtimeavg);

    printf("\nAverage Turnaround Time=%f\n",turnartimeavg);



    return 0;

}
