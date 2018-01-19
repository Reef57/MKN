program BO;
type
  point = record
    x, y, x1, y1: real;
  end;

function skal(x1, y1, x2, y2, x3, y3: real):real;
begin
     result := (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
end;

function cross(a, b:point):boolean;
var
  i: integer;
begin
     i := 0;
     if skal(a.x, a.y, a.x1, a.y1, b.x1, b.y1)*skal(a.x, a.y, a.x1, a.y1, b.x, b.y) < 0 then inc(i);
     if skal(b.x, b.y, b.x1, b.y1, a.x1, a.y1)*skal(b.x, b.y, b.x1, b.y1, a.x, a.y) < 0 then inc(i);
     if (skal(a.x, a.y, a.x1, a.y1, b.x, b.y) = 0) and (((a.x-b.x)*(a.x1-b.x)+(a.y-b.y)*(a.y1-b.y)) <= 0) then i := 2;
     if (skal(a.x, a.y, a.x1, a.y1, b.x1, b.y1) = 0) and (((a.x-b.x1)*(a.x1-b.x1)+(a.y-b.y1)*(a.y1-b.y1)) <= 0) then i := 2;
     if (skal(b.x, b.y, b.x1, b.y1, a.x1, a.y1) = 0) and (((b.x-a.x1)*(b.x1-a.x1)+(b.y-a.y1)*(b.y1-a.y1)) <= 0) then i := 2;
     if (skal(b.x, b.y, b.x1, b.y1, a.x, a.y) = 0) and (((b.x-a.x)*(b.x1-a.x)+(b.y-a.y)*(b.y1-a.y)) <= 0) then i := 2;
     if i = 2 then result := true else result := false;
end;

function poitcross(a, b:point):point;
var
  x: point;
begin
     x.x := ((a.x*a.y1-a.x1*a.y)*(b.x1-b.x)-(b.x*b.y1-b.x1*b.y)*(a.x1-a.x))/((a.y-a.y1)*(b.x1-b.x)-(b.y-b.y1)*(a.x1-a.x));
     x.y := ((b.y-b.y1)*x.x-(b.x*b.y1-b.x1*b.y))/(b.x1-b.x);
     x.x = -x.x;
     result := x;
end;

var
  v: array of point;
   xt, yt: real;
   n, i, k: integer;
begin
  write('Input number of vector: ');
  readln(n);
  setlength(v, n);
  for i := 0 to n-1 do
  begin
      writeln('Input point of vector: ');
      read(v[i].x);
      read(v[i].y);
      read(v[i].x1);
      read(v[i].y1);
      if v[i].x*v[i].y > v[i].x1*v[i].y1 then
      begin
        xt := v[i].x;
        yt := v[i].y;
        v[i].x := v[i].x1;
        v[i].y := v[i].y1;
        v[i].x1 := xt;
        v[i].y1 := yt;
      end;
  end;

  for i := 0 to n-2 do
      for k := i+1 to n-1 do
      begin
           if cross(v[i], v[k]) then
           begin
             writeln(i, ' ', k, ' cross');
             writeln(poitcross(v[i], v[k]).x:9:3, ' ', poitcross(v[i], v[k]).y:9:3, ' pointcross');
           end;
      end;
  readln(k);
end.

