#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct process {
    char name;
    int art, bt, ct, wt, tt;
    int completed;
    float ntt;
} p[10];

void sortByArrival(int n)
{
    struct process temp;
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {


            if (p[i].art > p[j].art) {


                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int hrrnn()
{
    int  i,j, t, sum_bt = 0;
    char c,d;
    float avgwt = 0, avgtt = 0;



    cout<<"Enter number of processes"<<endl;
    int n;
    cin>>n;
    process p[n];

    int burst[n],arriv[n];
    for(i=0,d='A';i<n;i++,d++)
    {
         p[i].name=d;
    }
    // Burst time of all processes
    cout<<"Enter burst time of each process"<<endl;

    for(i=0;i<n;i++)
    {
        cout<<"Process"<<p[i].name<<endl;
        cin>>burst[i];

    }
    cout<<"Enter arrival time of each process"<<endl;

    for(i=0;i<n;i++)
    {
        cout<<"Process"<<p[i].name<<endl;
        cin>>arriv[i];

    }



    for (i = 0, c = 'A'; i < n; i++, c++) {
        p[i].name = c;
        p[i].art = arriv[i];
        p[i].bt = burst[i];
        p[i].completed = 0;


        sum_bt += p[i].bt;
    }


    sortByArrival(n);
  cout<<"\nName\tArrival Time\tBurst Time\tWaiting Time";
  cout<<"\tTurnAround Time\t Normalized TT";
    for (t = p[0].art; t < sum_bt;) {

        float hrr = -9999;


        float temp;

        int loc;
        for (i = 0; i < n; i++) {


            if (p[i].art <= t && p[i].completed != 1) {


                temp = (p[i].bt + (t - p[i].art)) / p[i].bt;

                if (hrr < temp) {

                    hrr = temp;


                    loc = i;
                }
            }
        }


        t += p[loc].bt;


        p[loc].wt = t - p[loc].art - p[loc].bt;

        p[loc].tt = t - p[loc].art;

        avgtt += p[loc].tt;


        p[loc].ntt = ((float)p[loc].tt / p[loc].bt);

        p[loc].completed = 1;


        avgwt += p[loc].wt;
        cout<<"\n"<<p[loc].name<<"\t\t"<<p[loc].art;
        cout<<"\t\t"<<p[loc].bt<<"\t\t"<<p[loc].wt;
        cout<<"\t\t"<<p[loc].tt<<"\t\t"<<p[loc].ntt;
    }
    cout<<"\nAverage waiting time:"<<avgwt / n;
    cout<<"\nAverage Turn Around time:"<<avgtt / n;
    return 0;
}
int pc[10],sc[10],csc[10],its[10];
struct Process {
    int pid;
    int bt;
    int art;
};

void findWaitingTime_sjf(Process proc[], int n,
                                int wt[])
{
    int rt[n];


    for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;

    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;


    while (complete != n) {


        for (int j = 0; j < n; j++) {
            if ((proc[j].art <= t) &&
            (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = true;
                cout<<"p"<<j<<"\n";
            }
        }

        if (check == false) {
            t++;
            continue;
        }


        rt[shortest]--;


        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;

        if (rt[shortest] == 0) {


            complete++;


            finish_time = t + 1;


            wt[shortest] = finish_time -
                        proc[shortest].bt -
                        proc[shortest].art;

            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }

        t++;
    }
}

void findTurnAroundTime_sjf(Process proc[], int n,
                        int wt[], int tat[])
{

    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

void findavgTime()
{cout<<"Enter number of processes"<<endl;
    int n;
    cin>>n;
    Process proc[n];
    for(int i=0;i<n;i++)
    {
         proc[i].pid=i;
    }

    // Burst time of all processes
    cout<<"Enter burst time of each process"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<"Process"<<proc[i].pid<<endl;
        cin>>proc[i].bt;

    }
    cout<<"Enter arrival time of each process"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<"Process"<<proc[i].pid<<endl;
        cin>>proc[i].art;

    }
    int wt[n], tat[n], total_wt = 0,
                    total_tat = 0;


    findWaitingTime_sjf(proc, n, wt);

    findTurnAroundTime_sjf(proc, n, wt, tat);


    cout << "Processes "
        << " Burst time "
        << " Waiting time "
        << " Turn around time\n";


    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << proc[i].pid << "\t\t"
            << proc[i].bt << "\t\t " << wt[i]
            << "\t\t " << tat[i] << endl;
    }

    cout << "\nAverage waiting time = "
        << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
        << (float)total_tat / (float)n;
}

// Function to find the waiting time for all
// processes
int upperlimit(int x)
{
    if(x%2==1)
    {
        x=x+1;
        return x;
    }
    else
        return x;
}
void cal_pc(int priority[],int n)
    {

      int min=100;
       for(int i=0;i<n;i++)
       {
           if(min>=priority[i])
            min=priority[i];
       }
       for(int j=0;j<n;j++)
       {
           if(priority[j]==min)
            pc[j]=1;
  //          cout<<pc[j];
       }

//cout<<'\n';
    }
void cal_sc(int bt[],int n)
{sc[0]=0;
    for(int i=1;i<n;i++)
      {
          if(bt[i]-bt[i-1]<=0)
          {
              sc[i]=1;

          }
          else
            sc[i]=0;

  //  cout<<sc[i];
      }
    //  cout<<'\n';
}
void cal_csc(int bt[],int n,int qt)
{
    for(int i=0;i<n;i++)
    {//cout<<bt[i]<<pc[i]<<sc[i]<<qt<<'\n';
       int x=((bt[i]-pc[i])-sc[i]);
       int y=2*qt;
      // cout<<x<<y;
        if(x<y)
            {csc[i]=1;
            //cout<<csc[i];
            }
        else
            {csc[i]=0;
           // cout<<csc[i];
           }
    }
    cout<<'\n';
}
void cal_its(int n,int qt)
{
    for(int i=0;i<n;i++)
    {
        its[i]=pc[i]+sc[i]+qt+csc[i];
        //cout<<its[i];
    }
}
void findWaitingTime_mrr(int processes[], int n,
             int bt[], int wt[], int quantum)
{
    // Make a copy of burst times bt[] to store remaining
    // burst times.
    int rem_bt[n];
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] =  bt[i];

    int t = 0; // Current time

    // Keep traversing processes in round robin manner
    // until all of them are not done.
    while (1)
    {
        bool done = true;

        // Traverse all processes one by one repeatedly
        for (int i = 0 ; i < n; i++)
        {
            // If burst time of a process is greater than 0
            // then only need to process further
            if (rem_bt[i] > 0)
            {
                done = false; // There is a pending process

                if (rem_bt[i] > its[i])
                {
                    // Increase the value of t i.e. shows
                    // how much time a process has been processed
                    t += its[i];

                    // Decrease the burst_time of current process
                    // by quantum
                    rem_bt[i] -= its[i];
                    cout<<"p"<<i+1<<"\n";
                }

                // If burst time is smaller than or equal to
                // quantum. Last cycle for this process
                else
                {
                    // Increase the value of t i.e. shows
                    // how much time a process has been processed
                    t = t + rem_bt[i];
                    cout<<"p"<<i+1<<"\n";
                    // Waiting time is current time minus time
                    // used by this process
                    wt[i] = t - bt[i];

                    // As the process gets fully executed
                    // make its remaining burst time = 0
                    rem_bt[i] = 0;
                }
            }
        }

        // If all processes are done
        if (done == true)
          break;
    }
}

// Function to calculate turn around time
void findTurnAroundTime_mrr(int processes[], int n,
                        int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average time
void findavgTime_mrr()
{
   cout<<"Enter number of processes"<<endl;
    int n;
    cin>>n;
    int processes[n];
    for(int i=0;i<n;i++)
    {
        processes[i]=i;
    }

    // Burst time of all processes
    cout<<"Enter burst time of each process"<<endl;
    int bt[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Process"<<processes[i]<<endl;
        cin>>bt[i];

    }
cout<<"Enter priority of each process"<<endl;
    int priority[n];
    for(int i=0;i<n;i++)
    {
        cout<<"priority"<<processes[i]<<endl;
        cin>>priority[i];

    }
    // Time quantum
    int quantum=4;

    cal_pc(priority,n);
    cal_sc(bt,n);
    cal_csc(bt,n,quantum);
    cal_its(n,quantum);
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Function to find waiting time of all processes
    findWaitingTime_mrr(processes, n, bt, wt, quantum);

    // Function to find turn around time for all processes
    findTurnAroundTime_mrr(processes, n, bt, wt, tat);

    // Display processes along with all details
    cout << "Processes "<< " Burst time "
         << " Waiting time " << " Turn around time\n";

    // Calculate total waiting time and total turn
    // around time
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
             << wt[i] <<"\t\t " << tat[i] <<endl;
    }

    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n<<'\n';
}
void findWaitingTime_pbdrr(int processes[], int n,
             int bt[], int wt[], int quantum)
{
    // Make a copy of burst times bt[] to store remaining
    // burst times.
    int qtt[n];
    int rem_bt[n];
    for (int i = 0 ; i < n ; i++)
        {rem_bt[i] =  bt[i];
        qtt[i]=its[i];}
     int x=0;
    int t = 0; // Current time
    int round=0;
    // Keep traversing processes in round robin manner
    // until all of them are not done.
    while (1)
    {
        bool done = true;

        // Traverse all processes one by one repeatedly
        for (int i = 0 ; i < n; i++)
        {

            if(round==0)
            {
                if(sc[i]==0)
                {x=upperlimit(qtt[i]);
                  qtt[i]=(x/2);

                }
                else{qtt[i]=qtt[i];}
            }
            else
            {
                 if(sc[i]==0)
                {x=upperlimit(qtt[i]);
                  qtt[i]=(x/2)+qtt[i];
                }
                else{qtt[i]=(2*qtt[i]);}
            }
            if(rem_bt[i]-qtt[i]<=2)
                {qtt[i]=rem_bt[i];}
               // cout<<qtt[i]<<'\n';
            // If burst time of a process is greater than 0
            // then only need to process further
            if (rem_bt[i] > 0)
            {
                done = false; // There is a pending process

                if (rem_bt[i] > qtt[i])
                {
                    // Increase the value of t i.e. shows
                    // how much time a process has been processed
                    t += qtt[i];

                    // Decrease the burst_time of current process
                    // by quantum
                    rem_bt[i] -= qtt[i];
                    cout<<"p"<<i+1<<"\n";
                }

                // If burst time is smaller than or equal to
                // quantum. Last cycle for this process
                else
                {
                    // Increase the value of t i.e. shows
                    // how much time a process has been processed
                    t = t + rem_bt[i];
                     cout<<"p"<<i+1<<"\n";
                    // Waiting time is current time minus time
                    // used by this process
                    wt[i] = t - bt[i];

                    // As the process gets fully executed
                    // make its remaining burst time = 0
                    rem_bt[i] = 0;
                }
            }
        }
              round++;
        // If all processes are done
        if (done == true)
          break;
    }
}

// Function to calculate turn around time
void findTurnAroundTime_pbdrr(int processes[], int n,
                        int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average time
void findavgTime_pbdrr()
{
       cout<<"Enter number of processes"<<endl;
    int n;
    cin>>n;
    int processes[n];
    for(int i=0;i<n;i++)
    {
        processes[i]=i;
    }

    // Burst time of all processes
    cout<<"Enter burst time of each process"<<endl;
    int bt[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Process"<<processes[i]<<endl;
        cin>>bt[i];

    }
cout<<"Enter priority of each process"<<endl;
    int priority[n];
    for(int i=0;i<n;i++)
    {
        cout<<"priority"<<processes[i]<<endl;
        cin>>priority[i];

    }
    int quantum=4;
    cal_pc(priority,n);
    cal_sc(bt,n);
    cal_csc(bt,n,quantum);
    cal_its(n,quantum);
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Function to find waiting time of all processes
    findWaitingTime_pbdrr(processes, n, bt, wt, quantum);

    // Function to find turn around time for all processes
    findTurnAroundTime_pbdrr(processes, n, bt, wt, tat);

    // Display processes along with all details
    cout << "Processes "<< " Burst time "
         << " Waiting time " << " Turn around time\n";

    // Calculate total waiting time and total turn
    // around time
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
             << wt[i] <<"\t\t " << tat[i] <<endl;
    }

    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n<<'\n';
}


void ed()
{   int n;
    cout<<"enter the number of processes-"<<endl;
    cin>>n;
    int art[n];
    int bt[n];
    int deadline[n+1];
     int b;
    b=n;
    int t;
    cout<<"enter process"<<"   "<<"art"<<"   "<<"bt"<<"   "<<"deadline"<<endl;
    cout<<endl;
    cout<<endl;
    deadline[0]=0;
   int q=0;
    while(q!=n)
    {
        cout<<"     "<<q+1<<"        ";
        cin>>art[q+1];
        cin>>bt[q+1];
        cin>>deadline[q+1];
         if(art[q+1]>=deadline[q+1])
          t=0;
           else
            t=1;
            if(t==1)
        {cout<<"valid input!"<<endl;
        cout<<endl;
        cout<<endl;
        q++;
        }
     else
        {cout<<"invalid input-renter the values:"<<endl;
         cout<<endl;
         cout<<endl;
        }
     }
     int sum=0;
     int sum1=0;
     int total=0;
    for(int i=1;i<=n;i++)
    {
        sum=sum+art[i];
        sum1=sum1+bt[i];
    }
      int z=1;
       int minimum=INT_MAX;
       //int i=0;
       //int total=0;
       int m=INT_MAX;
       int wt[n];
       int d[n];
        int flag=0;
        //int t[n];
     for(int i=1;i<=n;i++)
       {d[i]=INT_MAX;}
       int c[n];

        for(int k=1;k<=n;k++)
        {c[k]=-1;
        wt[k]=0;
        }
       int g=0;
       int s=0;
    if(sum==0 && t==1)
    {
      int count=0;
        //int arr[20];
        //int c=0;
      while(count!=n)
    {
        for( int i=1;i<=n;i++)
        {
            if(minimum>=deadline[i])
              {   minimum=deadline[i];
                  z=i;}
        }
        for(int i=1;i<=n;i++)
        {
            if(minimum==deadline[i])
              {
                if(bt[z]>=bt[i])
                {
                    minimum=deadline[i];
                    z=i;
                }
              }
        }
        if(deadline[z]>=total+bt[z])
                  {
                      count++;
                      deadline[z]=INT_MAX;
                      minimum=INT_MAX;
                      wt[z]=wt[z]+total-art[z];
                      total=total+bt[z];
                      s=s+wt[z];
                      bt[z]=0;
                      cout<<"p"<<z<<" total="<<total<<"    ";
                      //z++;
                }
                    else
                    {
                        count++;
                        deadline[z]=INT_MAX;
                        minimum=INT_MAX;
                        bt[z]=0;
                        wt[z]=0;
                        cout<<"cannot execute"<<"   ";
                    }
              }
               cout<<endl;
               cout<<endl;
               float a;
              a = (float)s/n;
              cout<<"waiting time="<<endl;
              for(int g=1;g<=n;g++)
                {
                    cout<<g<<"   "<<wt[g]<<endl;
                }
                cout<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"average waiting time="<<a;
                cout<<endl;
         }
 else if(sum!=0 && t==1)
    {
        while(sum1!=0)
        {
            for(int i=1;i<=n;i++)
            {
                if(art[i]<=total && art[i]>=0 && art[i]<deadline[i])
                {
                    c[i]=art[i];

                    d[i]=deadline[i];
                    art[i]=-1;
                }
            }
            for(int k=1;k<=n;k++)
            {
                if(d[k]<minimum)
                {
                    minimum=d[k];
                    z=k;
                }
            }
            if(c[z]>=0 && d[z]!=INT_MAX && z!=g && total+bt[z]<=deadline[z])
           {
               wt[z]=wt[z]+total-c[z];
               cout<<wt[z]<<endl;
               g=z;

           }
             if(c[z]>=0 && d[z]!=INT_MAX && total+bt[z]<=deadline[z])
             {
            c[z]++;
            bt[z]--;
            sum1--;
            minimum=INT_MAX;
            if(z!=0)
            cout<<"total="<<total<<"     ";
            total++;
            cout<<"p"<<" "<<z<<"     "<<"total="<<total<<endl;
            g=z;
           }
           if (total+bt[z]>deadline[z] && z!=g)
           {   cout<<"total="<<total<<"  ";
           sum1=sum1-bt[z];
           bt[z]=0;
           minimum=INT_MAX;
               cout<<"can't execute p"<<z<<"   ";
               cout<<"total="<<total<<endl;
               g=z;
           }
           //g=z;
            for(int r=1;r<=n;r++)
            {
                if(c[r]!=-1 )
                    {flag=1;
                     break;
                    }
            }
            if(flag==0)
                {   cout<<"total="<<total<<"    ";
                    total++;
                cout<<"waiting"<<"  "<<"total="<<total<<"    "<<endl;
                }
            flag=0;
            if(bt[z]==0)
            {
                c[z]= -1;
            d[z]=INT_MAX;
            deadline[z]=INT_MAX;
            }
            }
            cout<<endl;
            cout<<endl;
            float f=0;
            cout<<"waiting time="<<endl;
            for(int h=1;h<=n;h++)
            {
                cout<<wt[h]<<endl;
                f=f+wt[h];

            }
            float o=(float)f/n;
            cout<<endl;
            cout<<"average waiting time="<<"  "<<o;
            cout<<endl;
            cout<<endl;

        }

    }
void findWaitingTime(int processes[], int n,
             int bt[], int wt[], int quantum)
{
    // Make a copy of burst times bt[] to store remaining
    // burst times.
    int rem_bt[n];
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] =  bt[i];

    int t = 0; // Current time

    // Keep traversing processes in round robin manner
    // until all of them are not done.
    while (1)
    {
        bool done = true;

        // Traverse all processes one by one repeatedly
        for (int i = 0 ; i < n; i++)
        {
            // If burst time of a process is greater than 0
            // then only need to process further
            if (rem_bt[i] > 0)
            {
                done = false; // There is a pending process

                if (rem_bt[i] > quantum)
                {
                    // Increase the value of t i.e. shows
                    // how much time a process has been processed
                    t += quantum;

                    // Decrease the burst_time of current process
                    // by quantum
                    rem_bt[i] -= quantum;
                    cout<<"process"<<i+1<<'\n';
                }

                // If burst time is smaller than or equal to
                // quantum. Last cycle for this process
                else
                {
                    // Increase the value of t i.e. shows
                    // how much time a process has been processed
                    t = t + rem_bt[i];

                    // Waiting time is current time minus time
                    // used by this process
                    wt[i] = t - bt[i];

                    // As the process gets fully executed
                    // make its remaining burst time = 0
                    rem_bt[i] = 0;
                    cout<<"process"<<i+1<<'\n';
                }
            }
        }

        // If all processes are done
        if (done == true)
          break;
    }
}

// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n,
                        int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average time
void findavgTime(int processes[], int n, int bt[],
                                     int quantum)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt, quantum);

    // Function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);

    // Display processes along with all details
    cout << "Processes "<< " Burst time "
         << " Waiting time " << " Turn around time\n";

    // Calculate total waiting time and total turn
    // around time
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
             << wt[i] <<"\t\t " << tat[i] <<endl;
    }

    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}

// Driver code
int rr()
{
    // process id's
    cout<<"Enter number of processes"<<endl;
    int n;
    cin>>n;
    int processes[n];
    for(int i=0;i<n;i++)
    {
        processes[i]=i;
    }

    // Burst time of all processes
    cout<<"Enter burst time of each process"<<endl;
    int burst_time[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Process"<<processes[i]<<endl;
        cin>>burst_time[i];

    }

    // Time quantum
    int quantum = 4;
    findavgTime(processes, n, burst_time, quantum);
    return 0;

}

//FCFS
void findWaitingTime2(int processes[], int n,
                          int bt[], int wt[])
{
    // waiting time for first process is 0
    wt[0] = 0;
cout<<"process"<<0<<'\n';
    // calculating waiting time
    for (int  i = 1; i < n ; i++ )
        {wt[i] =  bt[i-1] + wt[i-1] ;
        cout<<"process"<<i<<'\n';}
}

// Function to calculate turn around time

//Function to calculate average time
void findavgTime2( int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    //Function to find waiting time of all processes
    findWaitingTime2(processes, n, bt, wt);

    //Function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);

    //Display processes along with all details
    cout << "Processes  "<< " Burst time  "
         << " Waiting time  " << " Turn around time\n";

    // Calculate total waiting time and total turn
    // around time
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i+1 << "\t\t" << bt[i] <<"\t    "
            << wt[i] <<"\t\t  " << tat[i] <<endl;
    }

    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}

// Driver code
int fcfs()
{
       cout<<"Enter number of processes"<<endl;
    int n;
    cin>>n;
    int processes[n];
    for(int i=0;i<n;i++)
    {
        processes[i]=i;
    }

    // Burst time of all processes
    cout<<"Enter burst time of each process"<<endl;
    int burst_time[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Process"<<processes[i]<<endl;
        cin>>burst_time[i];

    }
    findavgTime2(processes, n,  burst_time);
    return 0;
}

//SJF


int input()
{
    int number;
    cin>>number;
    return(number);
}

int main()
{int exit=1;
    while(exit)
    {int j;
    cout<<"\n\nPress 0:exit"<<endl;
    cout<<"Press 1:Round Robin"<<endl;
    cout<<"Press 2:First Come First Serve"<<endl;
    cout<<"Press 3:Shortest Job First"<<endl;
    cout<<"Press 4:Priority Based Round Robin with Intelligent Time slice"<<endl;
    cout<<"Press 5:Earliest Deadline First"<<endl;
    cout<<"Press 6:Highest Response Ratio Next"<<endl;
    cout<<"Press 7:Modified round robin"<<endl<<endl;
    cout<<"Enter your choice:"<<endl;
    int choice=input();
    switch(choice)
    {
    case 1:
        {
            system("CLS");
            cout<<"Round Robin"<<endl;
            rr();
            break;
        }
    case 2:
        {
            system("CLS");
            cout<<"First Come First Serve"<<endl;
            fcfs();
            break;
        }
    case 3:
        {
            system("CLS");
            cout<<"Shortest Job First"<<endl;
            findavgTime();
            break;
        }
    case 4:
        {
            system("CLS");
            cout<<"Priority Based Round Robin with Intelligent Time slice"<<endl;
            findavgTime_pbdrr();

            break;
        }
    case 5:
        {
            system("CLS");
            cout<<"Earliest Deadline First"<<endl;
            ed();
            break;
        }
    case 6:
        {
            system("CLS");
            cout<<"Highest Response Ratio Next"<<endl;
            hrrnn();
            break;
        }
    case 7:
        {
            system("CLS");
            cout<<"Modified Round Robin"<<endl;
            findavgTime_mrr();
            break;
        }
        case 0:
        {
            cout<<"thankyou"<<endl;
            exit=0;
            break;
        }
    default:
        {
            cout<<"wrong input"<<endl;
        }

    }
    }
    return 0;
}

