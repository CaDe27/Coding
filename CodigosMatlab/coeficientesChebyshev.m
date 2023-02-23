function [tn] =coeficientesChebyshev(n)
    t1 = zeros(n+1,1);
    t2 = zeros(n+1,1);
    t2(1,1) = 1;
    t1(2,1) = 1;
    if n==0
        tn = t2;
    elseif n==1
        tn = t1;
    else
        tn = zeros(n+1, 1);
        for i = 2:n
            tn(1,1) = -t2(1,1);
            for j = 1:i
                %para el grado j
                 tn(j+1, 1) = 2*t1(j,1) - t2(j+1,1);
            end
            t2 = t1;
            t1 = tn; 
        end
    end
end