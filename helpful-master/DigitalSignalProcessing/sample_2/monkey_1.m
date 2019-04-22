% ʹ��˫���Ա任�����ChebyshevI�����ָ�ͨ�˲������۲�ͨ����ĺ����˥���Ƿ����Ҫ��
% fp = 300hz, rp = 1.2db, fs = 200hz, rs = 20db, T = 0.001s
clear;
clc;
clf;
fp = 300;
rp = 1.2;
fs = 200;
rs = 20;
T = 0.001;
% ת��������������
digit_wp = 2*pi*fp*T;
digit_ws = 2*pi*fs*T;
% Ԥ����
digit_wp = 2/T*tan(digit_wp/2);
digit_ws = 2/T*tan(digit_ws/2);
[n, wn] = cheb1ord(digit_wp, digit_ws, rp, rs, 's');
[b, a] = cheby1(n, rp, wn, 'high', 's');
% ����������ӷ�ĸ����ϵ��
[bz, az] = bilinear(b, a, 1/T);
[db, mag, pha, grd, w] = freqz_m(bz, az);
plot(w/pi, db);
grid on;
axis([0, 1, -80, 10])
