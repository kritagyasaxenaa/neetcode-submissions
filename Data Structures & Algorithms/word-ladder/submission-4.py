class Solution:            

    def ladderLength(self, start: str, end: str, s: List[str]) -> int:
        #basic idea is to construct a graph and neighbours would be all strings that are reachable, rest is just dfs, the problem is how to check reachability
        if not len(start)==len(end):
            return 0
        sorted(s)
        map={}#string and list of string
        a=s[0]
        s[0]=start
        s.append(a)
        for i in range(len(s)-1):
            for k in range(i+1,len(s)):
                a=s[i]
                b=s[k]
                if not len(a)==len(b):
                    continue
                fl=False
                for j in range(len(a)):
                    if not a[j]==b[j]:
                        fl=not fl
                        if not fl:
                            break
                if fl:
                    if a not in map:
                        map[a]=[b]
                    else:
                        map[a].append(b)
                    if b not in map:
                        map[b]=[a]
                    else:
                        map[b].append(a)
        print(map)
        q=set()
        qu=[start]
        res=1
        n=1
        #bfs 
        while len(qu):
            if(n==0):
                res+=1
                n=len(qu)
            curr=qu.pop(0)
            q.add(curr)
            n-=1
            if curr==end:
                return res
            if curr not in map:
                continue
            for i in map[curr]:
                if i not in q and i not in qu:
                    qu.append(i)
        return 0   