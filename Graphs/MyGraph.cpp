#ifndef MYGRAPH_H
#define MYGRAPH_H
#include <iostream>
#include "IntSLList.h"
#include <fstream>
#include <string>
#include <queue>


using namespace std;
class MyGraph{
private:
    bool error;
	IntSLList **listoflist;
	int arraysize;
	int *CheckList;
	void TurnDefault(void){
		for(int i=0;i<arraysize+1;i++){
			CheckList[i] = -1;
		}
	}
public:
	MyGraph(string filename){

		ifstream file;
		file.open(filename.c_str());
		file >> arraysize;
		if(file.is_open() == false){
            cout << "Couldn't open the file" << endl;
            error = true;
            return;
		}
		error = false;
		CheckList = new int [arraysize+1];
		TurnDefault();
		listoflist = new IntSLList *[arraysize];
		for(int i = 0;i<arraysize;i++){
			listoflist[i] = new IntSLList;
		}


		int from,to;
		int i = 0;
		while(file.eof() == false){
			file>>from;
			file>>to;


			listoflist[from-1]->addToTail(to);
		}
	}
	~MyGraph(){
        if(error == true) return;
		for(int i=0;i<arraysize;i++){
			delete listoflist[i];

		}
		delete [] listoflist;
		delete [] CheckList;
	}
	void print(void){
		for(int i = 0;i<arraysize;i++){
			cout << "Adjacencies of " << i+1 << "= ";
			listoflist[i]->printAll();
		}
	}
	void convert_adj_matrix(){


		int arr[arraysize][arraysize]={{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0}};

		for(int i=0;i<arraysize;i++){
                int j=0;
            for(;j<listoflist[i]->GetSize();j++){


                int n=listoflist[i]->GetAt(j+1);
                arr[i][n-1]=1;


            }
		}

		for(int i=0;i<arraysize;i++){
            for(int j=0;j<arraysize;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
		}

	}
	bool isConnected (int src, int dest){

     /*bool flag=false;
     for(int i=0;i<listoflist[src-1]->GetSize();i++){
            int n=listoflist[src-1]->GetAt(i+1);
            if(n==dest)
                return true;
            else{
                for(int j=0;j<listoflist[n-1]->GetSize();j++){
                    int t=listoflist[n-1]->GetAt(j+1);
                    if(t==dest)
                        return true;
                    else{
                        for(int r=0;r<listoflist[t-1]->GetSize();r++){
                            int l=listoflist[t-1]->GetAt(r+1);
                            if(l==dest)
                                return true;
                            else{
                                return false;
                            }
                        }

                }

                }

            }

     }*/
     queue<int> q;
     q.push(src);
     int visited[arraysize]={0,0,0,0,0,0,0};
     visited[src-1]=1;
     for(int i=0;i<listoflist[src-1]->GetSize();i++){
        q.push(listoflist[src-1]->GetAt(i+1));
        visited[listoflist[src-1]->GetAt(i+1)-1]=1;
     }
     q.pop();
     while(!q.empty()){
        int n=q.front();
        q.pop();
        if(n==dest)
            return true;

        for(int i=0;i<listoflist[n-1]->GetSize();i++){
            int m=listoflist[n-1]->GetAt(i+1);
            q.push(m);
            visited[m-1];
            if(m==dest)
                return true;
        }
     }
     return false;
     }


};

#endif
