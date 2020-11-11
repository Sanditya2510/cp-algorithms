void modBigNumber(string num, ll m)
{
    // Store the modulus of big number
    vector<int> vec;
    ll mod = 0;
    // Do step by step division
    for (int i = 0; i < num.size(); i++) {
        int digit = num[i] - '0';
        mod = mod * 10 + digit;
        int quo = mod / m;
        if((vec.size()!=0)||(quo!=0))        //to remove initiale zeros
        vec.push_back(quo);
        mod = mod % m;
    }
   // cout << "\nRemainder : " << mod << "\n";
   // cout << "Quotient : ";rep(i,0,vec.size()-1,1)cout<<vec[i];cout<<"\n";
    return;
}