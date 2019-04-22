function [Hr,w,b,L] = Hr_Type2(h);
% 计算第二种低通滤波器设计的振幅响应Hr(w) 
% -----------------------------------------------------------
%  [Hr,w,b,L] = Hr_Type2(h)
%  Hr = 振幅响应
%  w = 在[0 pi] 区间内计算Hr 的频率点
%  b = 第二种低通滤波器的系数
%  L = Hr的阶次
%  h = 第二种低通滤波器的频率响应
% 
M = length(h);
L = M/2;
b = 2*[h(L:-1:1)];
n = [1:1:L]; n = n-0.5;
w = [0:1:500]'*pi/500;
Hr = cos(w*n)*b';
