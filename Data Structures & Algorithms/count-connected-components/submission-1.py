class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        map={}#create graph
        m={}
        for a,b in edges:
            if a not in map:
                map[a]=[b]
            else:
                map[a].append(b)
            if b not in map:
                map[b]=[a]
            else:
                map[b].append(a)
        count=0
        for i in range(n):
            if i not in m:
                q=set()
                count+=1
                self.dfs(i,map,q,m)
        return count


    def dfs(self, i:int, map:dict, q:set, m:dict):
        if i in m or i in q: 
            return
        if i not in map:
            m[i]=True
            return
        q.add(i)
        for a in map[i]:
            if a not in q and a not in m:
                self.dfs(a,map,q,m)
        q.remove(i)
        m[i]=True
        return True

