clc
n = 3;
%A = [1 2 1; 2 1 1; 1 -1 2]
%A = [3 1 -1 2 6; -5 1 3 -4 -12; 2 0 1 -1 1; 1 -5 3 -3 3]
%A = [1 3 3 11; 1 -2 3 1; 3 3 -1 1]
A = [2 1 3 1; 11 7 5 -6; 9 8 4 -5]
L = zeros(n);
U = zeros(n);
y = zeros(1, n);
x = zeros(1, n);

for j = 1:1:n
   U(1, j) = A(1, j);
   L(j, 1) = A(j ,1)/U(1, 1);
end

for i = 2:1:n
   for j = i:1:n
      lu = 0;
      for k = 1:1:i-1
         lu = lu + L(i ,k)*U(k ,j); 
      end
      U(i, j) = A(i, j) - lu;
      
      lu = 0;
      for k = 1:1:i-1
         lu = lu + L(j ,k)*U(k ,i); 
      end
      L(j ,i) = (A(j ,i)-lu)/U(i, i);
   end
end

y(1, 1) = A(1, n+1)/L(1, 1);
for i = 2:1:n 
    by = 0;
    for k = 1:1:i-1
       by = by + L(i, k)*y(1, k); 
    end
    y(1, i) = (A(i, n+1)-by)/L(i, i);
end

x(1, n) = y(1 ,n)/U(n, n);
x
for i = n-1:-1:1 
    cx = 0;
    for k = i+1:1:n
        k
        i
        U(i ,k)
        x(1, k)
       cx = cx + U(i ,k)*x(1, k);
    end
    cx
    x(1, i) = (y(1, i) - cx)/U(i, i);
end
L
U
x


