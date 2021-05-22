// this code was used for finding minima of a function
// ll f(){
//     ....return
// }
ll ternary_search(ll l, ll r)
{
	while(r-l>=3)
	{
		ll mid1 = l + (r-l)/3;
		ll mid2 = r - (r-l)/3;
		if(f(mid1) < f(mid2))
			r = mid2;
		else
			 l = mid1;
	}
	if(l==r)
		return f(l);
	else if (l+1==r)
		return min(f(l), f(r));
	else
		return min(f(l), min(f(l+1), f(l+2)));
}