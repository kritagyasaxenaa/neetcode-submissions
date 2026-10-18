class Solution:

    def bfs(self,curr:str, target:str, s:List[str], q:set, qu:List[str]):
        if curr in q:
            return 0
        qu.pop(0)

        return 0
            

    def ladderLength(self, start: str, end: str, s: List[str]) -> int:
        #basic idea is to construct a graph and neighbours would be all strings that are reachable, rest is just dfs, the problem is how to check reachability
        if not len(start)==len(end) or end not in s:
            return 0
        a=s[0]
        s[0]=start
        s.append(a)
        sorted(s)
        q=set()
        qu=deque([start])
        n=len(qu)
        res=1
        while len(qu):
            if(n==0):
                n=len(qu)
                res+=1
            curr=qu.popleft()
            n-=1
            q.add(curr)
            alpha="abcdefghijklmnopqrstuvwxyz"
            for i in range(len(curr)):
                for k in alpha:
                    a=curr[:i]+k+curr[i+1:]
                    if a==curr:
                        continue
                    if a in s and a not in q and a not in qu:
                        if a==end:
                            return res+1
                        qu.append(a)

        return 0        