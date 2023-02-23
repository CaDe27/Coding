function [x,k] = metodoNewton2(fname, x0)
     %{
        IN: 
            fname   - nombre de la función
            x0      - valor de x en donde inicia 
                        el proceso
        OUT:
            x       - raíz aproximada
            k       - el numero de iteraciones
    %}
    
    %inicializo mis variables
    %en fx guardo f(x)
    x = x0;
    k = 0;
    fx = feval(fname, x);
    tolerancia = 1e-8;
    
     %repetimos el proceso mientras f(x) no este tan cerca de cero como
    %queramos
    while( abs(fx) > tolerancia)
        %calculamos la derivada
        %usamos 1e-5 por el resultado del laboratorio 11
        derivada = dif_centrada(fname, x, 1e-5);
        
        %hacemos la reasignación del método de Newton
        x = x - fx/derivada;
        
        %ajustamos k y  fx
        fx = feval(fname, x);
        k = k +1;
    end
end