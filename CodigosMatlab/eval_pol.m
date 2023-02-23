function [p] = eval_pol(c,a,w)
    n = length(c);
    p = c(n,1);
    for i = n-1:-1:1
       p = c(i,1) + p*(w - a(i,1));
    end
end