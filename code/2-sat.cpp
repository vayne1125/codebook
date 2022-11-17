//用在(a or b) and (b or c')這種題目
//假設有2個點(a,b) => a b a' b'用0123表示
//(a or b) 建立2條邊 (a,b') 和 (b,a') -> (0,3) (1,2)
//然後跑scc 他的true 或 false 看bln判斷 ans[i] = bln[i] < bln[i+n]
//然後再用ans的true false去核對條件看對不對 不對就沒有答案
//轉換技巧 ab' + a'b => ab' + a'b + aa' + bb' => a(a'+b') + b(a'+b') = (a+b)(a'+b')