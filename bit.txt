struct BIT
{
vector<ll>bitree;ll n;
BIT(ll n)
{
this->n=n;
bitree.resize(n+1,0);
}
void update(ll idx,ll val)
{
  idx++;
  while(idx<=n)
  {
    bitree[idx]+=val;
    idx+=idx&(-idx);
  }
}
ll Sum(ll idx)
{
  ll sum=0;
  idx++;
  while(idx>0)
  {
    sum+=bitree[idx];
    idx-=idx&(-idx);
  }
  return sum;
}
};