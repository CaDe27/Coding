function[x1, x2] = cuadratica(a,b,c)
    if(b < 0)
        a = a*-1;
        b = b*-1;
        c = c*-1;
    end
    disc = b^2 - 4*a*c;
    x1 = -2*c/(sqrt(disc)+b);
    x2 = -(b + sqrt(disc))/2/a;
end