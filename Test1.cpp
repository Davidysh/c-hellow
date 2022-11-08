int magicalString(int n) {
        string s;
        s = "122";
        int i = 2,j = 3;
        int number = 1;
        while(j < n){
            if(s[i] == '1'){
                s += s[j-1] == '1'?'2':'1';
                if(s[j-1] == '2')
                number++;
                j++;
            }
            else{
                s += s[j-1] == '1'?"22":"11";
                if(s[j-1] == '2')
                number += j + 2 <= n? 2:1;
                j += 2;
            }
            i++;
        }
        return number;
    }