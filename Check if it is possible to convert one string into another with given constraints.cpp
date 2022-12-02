int isItPossible(string S, string T, int M, int N) {
        // code here
        //First condition : the lengths must match
        if(M!=N) return 0;
        string s1="";
        string s2="";
        //second condition: the order of A's and B's must match as they can't cross each other.
        for(int i=0;i<M;i++)
        {
            if(S[i]=='#') ; //No operation
            else s1+=S[i];
            if(T[i]=='#') ; //NO operation
            else s2+=T[i];
        }
        if(s1!=s2) return 0;
        // Now the final condition
    //I can only reduce the # coming before A and reduce # coming after B
    /* I can not increase these two counts, so they has to be same or greater in S than T
     before altering string S */
        int hashBeforeA=0;
        int hashAfterB=0;
        int flag1=0; //flag to find last A
        int flag2=0; //flag to find fisrt B
        for(int i=0;i<M;i++)
        {
            if(S[i]=='B') flag1=1;
            if(T[i]=='B') flag2=1;
            if(flag1 && S[i]=='#') hashAfterB++;
            if(flag2 && T[i]=='#') hashAfterB--;
        }
        flag1=0; flag2=0;
        for(int i=M-1;i>=0;i--)
        {
            if(S[i]=='A') flag1=1;
            if(T[i]== 'A') flag2=1;
            if(flag1 && S[i]=='#') hashBeforeA++;
            if(flag2 && T[i]=='#') hashBeforeA--;
            
        }        
        if(hashAfterB >=0 && hashBeforeA >=0) return 1;
        return 0;
    }
