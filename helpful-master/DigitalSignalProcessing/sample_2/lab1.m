% ������Ӧ���䷨��ư�����˹��ͨ�˲���
% ����Ҫ��
% ͨ����ֹƵ�ʣ�analog_wp = 200*pi�� ͨ�����˥����rp = 3db
% �����ֹƵ�ʣ�analog_ws = 600*pi�� �����С˥����rs = 12db
% ����Ƶ�ʣ�fs = 1000hz
% 
clear;
clf;
wp = 200 * pi;
ws = 600 * pi;
rp = 3;
rs = 12;
[n, wn] = buttord(wp, ws, rp, rs,'s');
[b, a] = butter(n, wn, 's');
[db, ~, ~, w] = freqs_m(b, a, 500*2*pi);
plot(w/(2*pi), db);
axis([0, 500, -20, 1]);
hold on;
fs = 1000;
[bz, az] = impinvar(b, a, fs);
[db, mag, pha, grd, w] = freqz_m(bz, az);
plot(0.5*fs*w/pi, db);
axis([0, 500, -20, 1]);
hold off;