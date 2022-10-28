#include<bits/stdc++.h>
using namespace std;

    bool parseBoolExpr(string expression) {
        stack<char> in;
        stack<char> out;
        char ans;
        bool temp1;
        bool temp2;
        char f[expression.length()];
 
    int i;
    for (i = 0; i < sizeof(f); i++) {
        f[i] = expression[i];
    }
        for(int i=0;i<expression.length();i++)
        {
        if(f[i]=='&'|| f[i]=='|' ||f[i]=='!')
            out.push(f[i]);
        else if(f[i]=='(' || f[i]=='t' || f[i]=='f')
            in.push(f[i]);
        else if(f[i]==',' )
                continue;
        else if(f[i]==')')
        {
            while(in.top()!='(')
            {  
                    if(out.top()=='!')
                {   
                    if(!out.empty())
                    out.pop(); 
                    in.top()=='f'? temp1=false:temp1=true;
                    if(!in.empty())    
                    in.pop();
                    temp1=!temp1;
                    temp1==false ? in.push('f') : in.push('t');
                    ans=in.top();
                    if(!in.empty())    
                    in.pop();
                    if(!in.empty())    
                    in.pop();
                    in.push(ans);
                }
                else if(out.top()=='|')
                {
                        if(!out.empty())
                        out.pop();
                        while(in.top()=='t'|| in.top()=='f')
                        {
                        in.top()=='f'? temp1=false:temp1=true;
                        if(!in.empty())
                        in.pop();
                        in.top()=='f'? temp2=false:temp2=true;
                        if(!in.empty())
                        in.pop();
                        temp2=temp1|temp2;
                        temp2==false ? in.push('f') : in.push('t');
                        ans=in.top();
                        }
                        if(!in.empty())
                        in.pop();
                        if(!in.empty())
                        in.pop();
                        in.push(ans);
                }    
                else if(out.top()=='&')
                {       
                        if(!out.empty())
                        out.pop();
                        while(in.top()=='t'|| in.top()=='f')
                        {
                        in.top()=='f'? temp1=false:temp1=true;
                        if(!in.empty())    
                        in.pop();
                        in.top()=='f'? temp2=false:temp2=true;
                        if(!in.empty())    
                        in.pop();
                        temp2=temp1&temp2;
                        temp2==false ? in.push('f') : in.push('t');  
                        ans=in.top();
                        }    
                        if(!in.empty())
                        in.pop();
                        if(!in.empty())
                        in.pop();
                        in.push(ans);
                        
                }    
            } 
            
        }
        
        }   
        if(ans=='f')
            return false;
        else if(ans=='t')
            return true;
        return 0;
    }

int main()
{
    bool b1;
    string s="|(f,t)";
    b1=parseBoolExpr(s);
    cout << b1;
    return 0;
}