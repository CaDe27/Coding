function[x1, x2] = cuadraticaProblematica(a,b,c)
    disc = b^2 - 4*a*c;
    x1 = (-b + sqrt(disc))/2/a;
    x2 = (-b - sqrt(disc))/2/a;
end