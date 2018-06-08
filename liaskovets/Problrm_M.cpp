// problem_I.cpp: ���������� ����� ����� ��� ����������� ����������.
//


#include <vector>
#include <stdio.h>
#include <queue>
#include <iostream>
#include <fstream>
 
using namespace std;

int main ()
{
	ifstream fin("input.txt");
        vector < vector<int> > g; // ����
        int n; // ����� ������
        int start; // ��������� ������� (������� ����� ���������� � ����)
		int zviazki;
		//cin >> n;
		fin >> n;
		//cin >> zviazki;
		fin >> zviazki;
		
		
		// ������ �����
        
		bool **Adj= new bool* [n] ;
		for (int count = 0; count < n; count++)
			Adj[count] = new bool [n];

		
		bool *visited= new bool [n] ;
		for(int i = 0; i<n; i++)
		{
			visited[i]=0;
			for(int j = 0; j<n; j++)
			Adj[i][j]=0;
		}
		
		for(int i = 0; i<zviazki; i++)
		{
			int AA, BB;
		//cin >> AA>>BB;
			fin >> AA>>BB;
			Adj[AA-1][BB-1]=1;
			Adj[BB-1][AA-1]=1;
		}

		int misto=0;
		bool kinec=false;
		while(kinec==false)
		{
						start=0;
						while((visited[start]!=0)&&(start!=n))//������ �������� �������
							start++;
						
						if(start==n)
						kinec=true;
						else
						{
										//��������� ����� � �������
										for (int i = 0; i<n; i++)
										{
												g.push_back(vector<int>());
												for(int j = 0; j<n; j++)
												{
													if(Adj[i][j])
														g[i].push_back(j);
														
												}
										}
										queue<int> q;
										q.push (start);
										vector<bool> used (n);
										vector<int> d (n), p (n);
										used[start] = true;
										p[start] = -1;
										while (!q.empty()) {
												int v = q.front();
												q.pop();
												for (size_t i=0; i<g[v].size(); ++i) 
												{
														int to = g[v][i];
														if (!used[to]) 
														{
																used[to] = true;
																q.push (to);
															//	d[to] = d[v] + 1;
																//p[to] = v;
														}
												}
										}
			

										//�������� ����
		       /*�������� ����� ������*/cout<<"misto #"<<misto<<" = ";
			   /*�������� ����� ������*/for(int i=0;i<n;i++)
			   /*�������� ����� ������*/	if((used[i]!=0)||(i==start)) { cout<< i+1<<" "; visited[i]=true; /*������� �� �������� � ����� ���*/}
			   /*�������� ����� ������*/cout<<endl;
				
										
										misto++;
						}
		}
        /*�������� ����� ������*/cout<<"kilkist dorig ";
		cout<<misto -1<< endl;

        return 0;
}

