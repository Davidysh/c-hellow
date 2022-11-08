class Solution {
public:
    int Find1(vector<int> fruits,int basket1,int i)
    {
        while(fruits[i] == basket1)
        {
            i++;
        }
        return i;
    }
    int Find2(vector<int> fruits,int basket,int i)
    {
        while(fruits[i] == basket && i != -1)
        {
            i--;
        }
        return i;
    }
    int totalFruit(vector<int>& fruits) {
        int left = 0,right = 0;
        int New;
        int basket1 = fruits[0];
        New = Find(fruits,basket1,0);
        int basket2 = fruits[New];
        int len = fruits.size();
        int number = 0, temp = 0;
        while(right < len)
        {
            if(fruits[right] != basket1 && fruits[right] != basket2)
            {
                if(number < temp)
                {
                    number = temp;
                    temp = 0;
                }
                
                left = Find2(fruits,fruits[right - 1],right - 1);
                basket1 = fruits[right - 1];
                basket2 = fruits[right];

            }
            else
            {
                temp++;
                right++;
                cout<<temp;
            }
        }
        if(number < temp)
        {
            number = temp;
        }
        return number;
    }
};