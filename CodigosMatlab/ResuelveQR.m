function[x] = ResuelveQR(A, b)
    [Q,R] = miQR(A);
    %recordermos que Q' = Q^-1 
    y = Q'*b;
    x = ResuelveTS(R, y);
end