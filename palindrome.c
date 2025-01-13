int d,rev=0;
bool isPalindrome(int x) {
    int temp = x;
    while(x!=0)
    {
        d=x%10;
        rev=(rev*10)+d;
        x=x/10;
    }
    if(temp==rev)
        return true;
    else
        return false;
}
