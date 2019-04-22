% ʹ��kaiser����ʵ�ִ�ͨ�˲���
% �������ws1 = 0.2*pi  ��ͨ����wp1 = 0.35*pi
% �������ws2 = 0.8*pi  ��ͨ����wp2 = 0.65*pi
% �����С˥����60db�� ͨ�����˥����1db
clear;
clc;
ws1 = 0.2*pi; wp1 = 0.35*pi;  wp2 = 0.65*pi; ws2 = 0.8*pi;
rp = 1;
rs = 60;
wc1 = (ws1+wp1)/2;
wc2 = (ws2+wp2)/2;
N = 50;
n = [0:1:N-1];
hd1 = ideal_lp(wc1, N);
hd2 = ideal_lp(wc2, N);
w_result = (kaiser(N, 5.865))';
hd = hd2 - hd1;
h = hd.*w_result;
[db, mag, pha, grd, w] = freqz_m(h, 1);
plot(w/pi, db);