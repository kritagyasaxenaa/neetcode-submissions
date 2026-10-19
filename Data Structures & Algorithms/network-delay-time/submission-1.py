class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, p: int) -> int:
        map={} #source to destination cost
        out={}
        inv={}
        for a,b,c in times:
            map[(a,b)]=c            
            if a not in out:
                out[a]=[b]
            else:
                out[a].append(b)
            if b not in inv:
                inv[b]=[a]
            else:
                inv[b].append(a)
        for i in range(n):
            if i+1 not in inv and not i+1==p:
                return -1   #unreachable node
            for j in range(n):
                if i==j:#same node
                    continue
                if i+1 not in out:
                    continue
                var=[]
                for k in out[i+1]:
                    if (k,j+1) not in map:
                        continue
                    cost=map[(k,j+1)]+map[(i+1,k)]
                    if (i+1,j+1) not in map:
                        map[(i+1,j+1)]=cost
                        var.append(j+1)
                    else:
                        map[(i+1,j+1)]=min(map[(i+1,j+1)],cost)
                for k in var:
                    out[i+1].append(k)
        i=p-1
        if i+1 not in inv and not i+1==p:
            return -1   #unreachable node
        for j in range(n):
            if i==j:#same node
                continue
            if i+1 not in out:
                continue
            var=[]
            for k in out[i+1]:
                if (k,j+1) not in map:
                    continue
                cost=map[(k,j+1)]+map[(i+1,k)]
                if (i+1,j+1) not in map:
                    map[(i+1,j+1)]=cost
                    var.append(j+1)
                else:
                    map[(i+1,j+1)]=min(map[(i+1,j+1)],cost)
            for k in var:
                out[i+1].append(k)
        ret=-1
        for i in range(n):
            if i+1==p:
                continue
            if i+1 not in out[p]:
                return -1
            ret=max(ret,map[(p,i+1)])
        return ret


        