
x1 = [1 2 3 4 5];
x2 = x1.*100000;
x3 = [x1(1:4) x2(5)];

%ponemos en una matriz los vectores
%para poder acceder a ellos en el for

X = [x1; x2; x3]
for i= 1:3
    i
    original = X(i, :)
    misoft = mi_softmax(X(i, :))'
    misoft2 = mi_softmax2(X(i, :))'
    matlabsoft = softmax(X(i,:)')'
end

%{

    los resultados de misoftmax2 y softmax matlab son los mismos
    
    mi_softmax2 funciona mucho mejor que mi_softmax1 porque el vector z creado
    tiene componentes no positiva y la exponencial arroja solo con
    numeros entre 0 y 1 que no causan el overflow que si ocurre en mi_softmax1

    Podria haber underflow?
	No en el denominador porque es mayor o igual a 1, porque la componente
	del maximo en z es 0,y e^0 = 1.
	Lo que si puede pasar es que un numero sea mucho mas pequenio que el max
	y en esa componente matlab podria arrojar e^xi = 0, pero esto esta bien
	porque su tamanio relativo es muy poco
%}



