
#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;
 int V=6;

int breath(int ResG[][6], int s, int t, int p[])
{

    bool VN[6];
    memset(VN, -1, sizeof(VN));
    queue<int> qu;
    qu.push(s);
    VN[s] = 1;
    p[s] = -1;

    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
 
        for (int v = 0; v < V; v++) {
            if (VN[v] == 0 && ResG[u][v] > 0) {
              
                if (v == t) {

                    p[v] = u;
                    return 1;
                }
                qu.push(v);
                p[v] = u;
                VN[v] = 1;
            }
        }
    }
 
    return 0;
}
 
int ff(int G[][6], int s, int t)
{
    int u, v;
    int ResG[6][6]; 
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            ResG[u][v] = G[u][v];
 
    int p[V]; 
    int m_flow = 0; 
    while(breath(ResG, s, t, p)==1) 
    {
        int p_flow = INT_MAX;
        for (v = t; v != s; v = p[v]) 
        {
            u = p[v];
            p_flow = min(p_flow, ResG[u][v]);
        }
 
 
      int k=-1;
       int v1[12];
       int u1[12];
        for (v =t ; v != s; v = p[v]) 
        {
             k++;
            u = p[v];
            ResG[u][v] -= p_flow;
            ResG[v][u] += p_flow;
            v1[k]=v;
            
            
            u1[k]=u;
    
           
            
        }
        m_flow += p_flow;
        cout<<"\nPath:";
        for(int i=k;i>=0;i--)
        {
            
            if(u1[i]==0)
            cout<<" s--V"<<v1[i];
            else if(v1[i]==t)
            cout<<" V"<<u1[i]<<"--t ";
            else cout<<" V"<<u1[i]<<"--V"<<v1[i];
        }
        k=-1;
        cout<<"\nFlow of this path:"<<p_flow<<"\n";
        cout<<"\nMax Path flow:"<<m_flow<<"\n";
    }
    cout<<"\n FINAL GRAPH \n";
 for(int i=0;i<V;i++)
 {
    for(int j=0;j<V;j++)
    {
        
         if(i==j||ResG[i][j]==0)
        continue;
        else if(i==0)
        cout<<"The flow between s and V"<<j<<" ";
        else if(j==0)
        cout<<"The flow between V"<<i<<" s ";
        else if(i==V-1)
        cout<<"The flow between t and V"<<j<<" ";
        else if(j==V-1)
        cout<<"The flow between V"<<i<<" t "; 
        else
        cout<<"The flow between V"<<i<<" V"<<j<<"  ";
        cout<<ResG[i][j]<<endl;
    }
 }
  
    return m_flow;
}
 

int main()
{
    


 int G[6][6]= {
{0,16,13,0,0,0},
{0,0,0,12,0,0},
{0,4,0,0,14,0},
{0,0,9,0,0,20},
{0,0,0,7,0,4},
{0,0,0,0,0,0}

};


/*
int G[8][8];
for(int i=0;i<V;i++)
{
    for(int j=0;j<V;j++)
    {
        if(i==j)
        continue;
        else if(i==0)
        cout<<"Enter the capacity between s and V"<<j;
        else if(j==0)
        cout<<"Enter the capacity between V"<<i<<" s";
        else if(i==V-1)
        cout<<"Enter the capacity between t and V"<<j;
        else if(j==V-1)
        cout<<"Enter the capacity between V"<<i<<" t"; 
        else
        cout<<"Enter the capacity between V"<<i<<" V"<<j<<":";
        cin>>G[i][j];
    }
}
   
*/
    cout << "The MAX FLOW = "<< ff(G, 0, V-1);
    
 
   return 0;
}