% ˫���Ա任�����ChebyshevI�͸�ͨ�˲���
% ����Ҫ��
% ͨ������Ƶ�ʣ�fp = 300hz�� ͨ�����˥����1.2db
% �������Ƶ�ʣ�fs = 200hz�� �����С˥����20db
% �������ڣ�0.001s
clear;
clc;
clf;
fp = 300;
rp = 1.2;
fs = 200;
rs = 20;
T = 0.001;
digit_wp = 2*pi*fp*T;
digit_ws = 2*pi*fs*T;
%Ԥ����
digit_wp = 2/T*tan(digit_wp/2);
digit_ws = 2/T*tan(digit_ws/2);
[n, wn] = cheb1ord(digit_wp, digit_ws, rp, rs, 's');
[b, a] = cheby1(n, rp, wn, 'high', 's');
[bz, az] = bilinear(b, a, 1/T);
[db, mag, pha, grd, w] = freqz_m(bz, az);
plot(w/pi, db);
axis([0, 1, -30, 2])