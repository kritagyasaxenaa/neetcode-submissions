class Solution:
    def dfs(self, i:int, map:dict, q:set, m: dict)->bool:
        if i in m:
            return True
        if i in q:
            return False
        if i not in map:
            m[i]=True
            return True
        q.add(i)
        var=True
        for a in map[i]:
            var = var and self.dfs(a, map, q, m)
        q.remove(i)
        if var:
            m[i]=True
        return var


    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        #basically to detect cycle:
        map={} # to store nodes and directions
        m={}# to store if already done
        for a,b in prerequisites:
            if a not in map:
                map[a]=[b]
            else:
                map[a].append(b)
        for i in range(numCourses):
            q=set()
            if(not self.dfs(i,map,q,m)):
                return False
        return True