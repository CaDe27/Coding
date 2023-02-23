function[y] = evaluaPoliBaseNewton (c, p, x)
    lenX = length(x);
    y = zeros(lenX,1);
    for i = 1: lenX
        y(i,1) = eval_pol(c,p,x(i,1));
    end
end

%{
function[y] = evaluaPoliBaseNewton (c, p, x)
    lenX = length(x);
    lenP = length(p);
    y = zeros(lenX,1);
    for i = 1: lenX
        aux  =  ones(lenP, 1);
        for j = 2:lenP
            aux(j, 1) = aux(j-1,1) * (x(i,1) - p(j-1, 1));
        end
        y(i,1) = dot(c, aux);
    end
end
%}