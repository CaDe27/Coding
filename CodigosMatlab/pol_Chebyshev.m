function[y] = pol_Chebyshev(x, n)
    c = coeficientesChebyshev(n);
    size = length(x);
    y = zeros(size, 1);
    for i = 1:size
        y(i,1) = eval_pol(c,zeros(n,1), x(i,1));
    end
end