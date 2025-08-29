'デバイスアラーム検出

tmr(systemwait,#30)

if systemwait.B then
'===================================================================================================================
'【 非常停止 】



'===================================================================================================================
'【  デバイスのアラーム検出  】
'-----------------------------------------------------------


'① KL-N20V  KLリンクリレーコントローラ


'② KL-L21V Modbus通信(リトライ通信中： 接続に異常がなければ自動復帰します ）

	select case ModbusC1AlmID

	case 0	'正常
		温度調節器1通信Alm=OFF
		温度調節器2通信Alm=OFF
		温度調節器3通信Alm=OFF
		温度調節器4通信Alm=OFF
		温度調節器5通信Alm=OFF
		温度調節器6通信Alm=OFF
		インバータ1通信Alm=OFF
		インバータ2通信Alm=OFF
		インバータ3通信Alm=OFF
		インバータ4通信Alm=OFF

	'----------------------------------
	case 1
		温度調節器1通信Alm=ON
	case 2
		温度調節器2通信Alm=ON
	case 3
		温度調節器3通信Alm=ON
	case 4
		温度調節器4通信Alm=ON
	case 5
		温度調節器5通信Alm=ON
	case 6
		温度調節器6通信Alm=ON
	'----------------------------------
	case 10
		インバータ1通信Alm=ON
	case 11
		インバータ2通信Alm=ON
	case 12
		インバータ3通信Alm=ON
	case 13
		インバータ4通信Alm=ON
	'----------------------------------

	end select

'③ KL-L21V Modbus通信(リトライ通信中： 接続に異常がなければ自動復帰します）

	select case ModbusC2AlmID
	case 0	'正常
		ADR4410ch1通信Alm=OFF
		ADR4410ch2通信Alm=OFF
		AD4532ch1通信Alm=OFF

	'----------------------------------
	case 1	
		ADR4410ch1通信Alm=ON
	case 2	
		ADR4410ch2通信Alm=ON
	'----------------------------------
	case 10	
		AD4532ch1通信Alm=ON
	'----------------------------------

	end select

'-----------------------------------------------------------
'操作ボックスの電源確認

'-- 納米庫
if 0 then '---- 納米庫を外した状態 ----
	if not(RLY_電源確認納米庫) then
		almRLY_電源確認納米庫=ON
		自動搬送ErrStep=1
	end if
else
	RLY_電源確認納米庫=ON
end if

'-----------------------------------------------------------
'操作ボックスの電源確認
'-- 浸漬A,B,注水
if LDP(not(RLY_浸漬電源確認)) then
	almRLY_浸漬電源確認=ON
	自動搬送ErrStep=1
end if	

'-- 搬送コンベアB
if LDP(not(RLY_搬送コンベアB電源確認)) then
	almRLY_搬送コンベアB電源確認=ON
	自動搬送ErrStep=1
end if
'-- むらし機
if LDP(not(RLY_むらし電源確認)) then
	almRLY_むらし電源確認=ON
	自動搬送ErrStep=1
end if
'-- 洗浄機
if LDP(not(RLY12_電源確認リレー)) and not(洗浄搬送禁止) then
	almRLY12_電源確認リレー=ON
	自動搬送ErrStep=1
end if
'-- 反転幾A
if LDP(not(電源確認リレー_A)) and not(反転ほぐし機A禁止) then
	alm電源確認リレー_A=ON
	自動搬送ErrStep=1
end if
'-- 反転幾B
if LDP(not(電源確認リレー_B)) and not(反転ほぐし機B禁止) then
	alm電源確認リレー_B=ON
	自動搬送ErrStep=1
end if
'-- 炊飯機
if LDP(not(INV4_コンベア電源確認)) then
	almINV4_コンベア電源確認=ON
	自動搬送ErrStep=1
end if

'-----------------------------------------------------------
'デジタル圧力計のアラーム検出


'-----------------------------------------------------------
'空圧スイッチ
if not(PS1_エアー圧力) or not(PS2_エアー圧力) or not(PS3_エアー圧力) then
	if not(PS1_エアー圧力) then
		almPS1_エアー圧力=ON
		自動搬送ErrStep=1
	end if
	if not(PS2_エアー圧力) then
		almPS2_エアー圧力=ON
		自動搬送ErrStep=1
	end if
	if not(PS3_エアー圧力) then
		almPS3_エアー圧力=ON
		自動搬送ErrStep=1
	end if
end if

'-----------------------------------------------------------
'モータ過負荷 THR、ショックリレー、INVアラーム

if LDP(THR4_送米ポンプ and RLY_電源確認納米庫) then
	almTHR4_送米ポンプ=ON
	mMC4_送米ポンプ=OFF
	ejectMC4_送米ポンプ=OFF
	自動搬送ErrStep=1
end if
if LDP(THR5_洗米羽根 and RLY_電源確認納米庫) then
	almTHR5_洗米羽根=ON
	mMC5_洗米羽根=OFF
	ejectMC5_洗米羽根=OFF
	自動搬送ErrStep=1
end if
if LDP(THR1_張込用昇降機モータ and RLY_電源確認納米庫) then
	almTHR1_張込用昇降機モータ=ON
	mMC1_張込用昇降機=OFF
	ejectMC1_張込用昇降機=OFF
	自動搬送ErrStep=1
end if
if LDP(THR2_排出用昇降機モータ and RLY_電源確認納米庫) then
	almTHR2_排出用昇降機モータ=ON
	mMC2_排出用昇降機=OFF
	ejectMC2_排出用昇降機=OFF
	自動搬送ErrStep=1
end if
if LDP(THR3_計量機モータ and RLY_電源確認納米庫) then
	almTHR3_計量機モータ=ON
	mMC3_計量機=OFF
	ejectMC3_計量機=OFF
	自動搬送ErrStep=1
end if

'搬送コンベアA
if LDP(THR6_搬送モータ and RLY_浸漬電源確認) then
	almTHR6_搬送モータ=ON
	mMC6_搬送モータ=OFF
	ejectMC6_搬送モータ=OFF
	自動搬送ErrStep=1
end if
if LDP(THR7_搬送モータ and RLY_浸漬電源確認) then
	almTHR7_搬送モータ=ON
	mMC7_搬送モータ=OFF
	ejectMC7_搬送モータ=OFF
	自動搬送ErrStep=1
end if
if LDP(THR8_搬送モータ and RLY_浸漬電源確認) then
	almTHR8_搬送モータ=ON
	mMC8_搬送モータ=OFF
	ejectMC8_搬送モータ=OFF
	自動搬送ErrStep=1
end if

'搬送コンベアB
if LDP(THR12_搬送モータ and RLY_搬送コンベアB電源確認) then
	almTHR12_搬送モータ=ON
	mMC12_搬送モータ=OFF
	ejectMC12_搬送モータ=OFF
	自動搬送ErrStep=1
end if
if LDP(THR13_搬送モータ and RLY_搬送コンベアB電源確認) then
	almTHR13_搬送モータ=ON
	mMC13_搬送モータ=OFF
	ejectMC13_搬送モータ=OFF
	自動搬送ErrStep=1
end if

'搬送コンベアC
if LDP(THR14_搬送モータ and RLY_搬送コンベアB電源確認) then
	almTHR14_搬送モータ=ON
	mMC14_搬送モータ=OFF
	ejectMC14_搬送モータ=OFF
	自動搬送ErrStep=1
end if
if LDP(THR15_搬送モータ and RLY_搬送コンベアB電源確認) then
	almTHR15_搬送モータ=ON
	mMC15_搬送モータ=OFF
	ejectMC15_搬送モータ=OFF
	自動搬送ErrStep=1
end if

'炊飯入口
if LDP(THR34_釜送りコンベア and RLY_搬送コンベアB電源確認) then
	almTHR34_釜送りコンベア=ON

	mMC34_釜送り正転=OFF
	ejectMC34_釜送り正転=OFF
	mMC34_釜送り逆転=OFF
	ejectMC34_釜送り逆転=OFF

	自動搬送ErrStep=1
end if

'乗り換え
if LDP(THR43_乗移コンベア and RLY_搬送コンベアB電源確認) then
	almTHR43_乗移コンベア=ON
	mMC43_乗移コンベア=OFF
	ejectMC43_乗移コンベア=OFF
	自動搬送ErrStep=1
end if

'炊飯出口
if LDP(THR18_釜送りコンベア and RLY_むらし電源確認) then
	almTHR18_釜送りコンベア=ON

	mMC18_釜送り正転=OFF
	ejectMC18_釜送り正転=OFF
	mMC18_釜送り逆転=OFF
	ejectMC18_釜送り逆転=OFF

	自動搬送ErrStep=1
end if

'むらし機
if LDP(THR17_むらし機モータ and RLY_むらし電源確認) then
	almTHR17_むらし機モータ=ON
	'mMC17_むらし機モータ=OFF
	自動搬送ErrStep=1
end if
if CSR1_ショックリレー then
	almCSR1_ショックリレー=ON
	'mMC17_むらし機モータ=OFF
	自動搬送ErrStep=1
end if


'搬送コンベアD
if LDP(THR19_搬送モータ and RLY_むらし電源確認) then
	almTHR19_搬送モータ=ON
	mMC19_搬送モータ=OFF
	ejectMC19_搬送モータ=OFF
	自動搬送ErrStep=1
end if
if LDP(THR20_搬送モータ and RLY_むらし電源確認) then
	almTHR20_搬送モータ=ON
	mMC20_搬送モータ=OFF
	ejectMC20_搬送モータ=OFF
	自動搬送ErrStep=1
end if
if LDP(THR21_搬送モータ and RLY_むらし電源確認) then
	almTHR21_搬送モータ=ON
	mMC21_搬送モータ正転=OFF
	ejectMC21_搬送モータ正転=OFF
	mMC21_搬送モータ逆転=OFF
	ejectMC21_搬送モータ逆転=OFF
	自動搬送ErrStep=1
end if
if LDP(THR22_搬送モータ and RLY_むらし電源確認) then
	almTHR22_搬送モータ=ON
	mMC22_搬送モータ正転=OFF
	ejectMC22_搬送モータ正転=OFF
	mMC22_搬送モータ逆転=OFF
	ejectMC22_搬送モータ逆転=OFF
	自動搬送ErrStep=1
end if

'バキュームポンプ
if LDP(THR24_吸引ポンプ and RLY_むらし電源確認) then
	almTHR24_吸引ポンプ=ON
	mMC24_吸引ポンプ=OFF
	ejectMC24_吸引ポンプ=OFF
	自動搬送ErrStep=1
end if

'搬送コンベアE
if LDP(THR25_搬送モータ and RLY_むらし電源確認) then
	almTHR25_搬送モータ=ON
	mMC25_搬送モータ=OFF
	ejectMC25_搬送モータ=OFF
	自動搬送ErrStep=1
end if
if LDP(THR26_搬送モータ and RLY_むらし電源確認) then
	almTHR26_搬送モータ=ON
	mMC26_搬送モータ=OFF
	自動搬送ErrStep=1
end if


'搬送コンベアF
if LDP(THR28_搬送モータ and RLY_むらし電源確認) then
	almTHR28_搬送モータ=ON
	mMC28_搬送モータ正転=OFF
	ejectMC28_搬送モータ正転=OFF
	mMC28_搬送モータ逆転=OFF
	ejectMC28_搬送モータ逆転=OFF
	自動搬送ErrStep=1
end if
if LDP(THR29_搬送モータ and RLY_むらし電源確認) then
	almTHR29_搬送モータ=ON
	mMC29_搬送モータ正転=OFF
	ejectMC29_搬送モータ正転=OFF
	mMC29_搬送モータ逆転=OFF
	ejectMC29_搬送モータ逆転=OFF
	自動搬送ErrStep=1
end if


'釜フタ昇降A
if LDP(THR30_搬送モータ and RLY_むらし電源確認) then
	almTHR30_搬送モータ=ON
	mMC30_搬送モータ=OFF
	ejectMC30_搬送モータ=OFF
	自動搬送ErrStep=1
end if

'反転幾入口
if LDP(THR31_反転モータ and RLY_むらし電源確認) then
	almTHR31_反転モータ=ON
	mMC31_反転モータ正転=OFF
	ejectMC31_反転モータ正転=OFF
	mMC31_反転モータ逆転=OFF
	ejectMC31_反転モータ逆転=OFF
	自動搬送ErrStep=1
end if

'反転幾出口
if LDP(THR10_反転モータ and RLY_浸漬電源確認) then
	almTHR10_反転モータ=ON
	
	mMC10_反転モータ正転=OFF
	ejectMC10_反転モータ正転=OFF
	mMC10_反転モータ逆転=OFF
	ejectMC10_反転モータ逆転=OFF
	
	自動搬送ErrStep=1
end if

'釜フタ昇降B

'-----------------------------------------------------------
'インバータアラーム

if not(洗浄搬送禁止) then


if MC1_インバータ用電源 or not(RLY12_電源確認リレー) then
	if anda(getM14c1,statALM)=statALM or  インバータ1Alm then
		almINV1_コンベア異常=ON
		mINV1_コンベアモータ正転=OFF
		ejectINV1_コンベアモータ正転=OFF
		自動搬送ErrStep=1
	end if
	if  anda(getM14c2,statALM)=statALM or インバータ2Alm then
		almINV2_コンベア異常=ON
		mINV2_コンベアモータ正転=OFF
		ejectINV2_コンベアモータ正転=OFF
		自動搬送ErrStep=1
	end if
	if  anda(getM14c3,statALM)=statALM or インバータ3Alm then
		almINV3_コンベア異常=ON
		mINV3_コンベアモータ正転=OFF
		ejectINV3_コンベアモータ正転=OFF
		自動搬送ErrStep=1
	end if
end if

end if

if INV4_コンベア電源確認 then
	if  anda(getM14c4,statALM)=statALM or インバータ4Alm or INV4_コンベア異常 then
		almINV4_コンベア異常=ON
		自動搬送ErrStep=1
	end if
end if

'-----------------------------------------------------------
'洗浄ポンプアラーム

'機械を停止させません。
'洗浄禁止状態のときは検出しません。
'リセット、あるいは洗浄禁止で解除します。

if PB34_リセット or PB24_リセット or PB6_リセット then
	almTHR35_洗浄ポンプA=OFF
	almTHR36_洗浄ポンプB=OFF
	almTHR37_洗浄ポンプC=OFF
	almTHR38_洗浄ポンプD=OFF
	almTHR39_洗浄ポンプE=OFF

else

	if LDP(THR35_洗浄ポンプA) and not(洗浄ユニット1禁止) then
		mMC35_洗浄ポンプA=OFF
		almTHR35_洗浄ポンプA=ON
	else 
		almTHR35_洗浄ポンプA=OFF
	end if

	if LDP(THR36_洗浄ポンプB) and not(洗浄ユニット2禁止) then
		mMC36_洗浄ポンプB=OFF
		almTHR36_洗浄ポンプB=ON
	else
		almTHR36_洗浄ポンプB=OFF
	end if

	if LDP(THR37_洗浄ポンプC) and not(洗浄ユニット3禁止) then
		mMC37_洗浄ポンプC=OFF
		almTHR37_洗浄ポンプC=ON
	else
		almTHR37_洗浄ポンプC=OFF
	end if

	if LDP(THR38_洗浄ポンプD) and not(洗浄ユニット4禁止) then
		mMC38_洗浄ポンプD=OFF
		almTHR38_洗浄ポンプD=ON
	else
		almTHR38_洗浄ポンプD=OFF
	end if

	if LDP(THR39_洗浄ポンプE) and not(洗浄ユニット5禁止) then
		mMC39_洗浄ポンプE=OFF
		almTHR39_洗浄ポンプE=ON
	else
		almTHR39_洗浄ポンプE=OFF
	end if

end if

'===================================================================================================================
if 0 then
	if almPH51_フタ検知=ON then

	else if almPH2_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH4_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH53_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH6_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH12_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH14_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH16_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH18_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH20_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH24_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH26_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH28_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH30_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH33_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH35_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH37_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH49_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH42_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH44_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH46_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH8_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH10_フタ検知=ON then
		自動搬送ErrStep=1

	else if almPH40_フタ検知=ON then
		自動搬送ErrStep=1

	end if
	
end if
'===================================================================================================================

'-----------------------------------------------------------
'温度調節器アラーム
'
'●	EDC_ST1LBT0	1ワード符号なし整数	#1	$1:ヒータ電流値オーバー（CT1）
'●	EDC_ST1LBT1	1ワード符号なし整数	#2	$2:ヒータ電流値ホールド(CT1)
'●	EDC_ST1LBT2	1ワード符号なし整数	#4	$4:ADコンバータ異常
'●	EDC_ST1LBT3	1ワード符号なし整数	#8	$8:HS（SSR故障）警報(CT1)
'●	EDC_ST1LBT4	1ワード符号なし整数	#16	$10:RSP入力異常
'●	EDC_ST1LBT6	1ワード符号なし整数	#64	$40:入力異常
'●	EDC_ST1LBT7	1ワード符号なし整数	#128	$80:ポテンションメータ入力異常
'	EDC_ST1LBT8	1ワード符号なし整数	#256	$100:制御出力(加熱）オープン出力
'	EDC_ST1LBT9	1ワード符号なし整数	#512	$200:制御出力(冷却)クローズ出力
'	EDC_ST1LBT10	1ワード符号なし整数	#1024	$400:HB(ヒータ断線）警報(CT1)
'	EDC_ST1LBT11	1ワード符号なし整数	#2048	$800:HB(ヒータ断線）警報(CT2)
'	EDC_ST1LBT12	1ワード符号なし整数	#4096	$1000:警報1
'	EDC_ST1LBT13	1ワード符号なし整数	#8192	$2000:警報2
'	EDC_ST1LBT14	1ワード符号なし整数	#16384	$4000:警報3
'	EDC_ST1LBT15	1ワード符号なし整数	#32768	$8000:プログラムエンド出力
'
	EDC_Almbit=0
	EDC_Almbit=ORA(EDC_Almbit,EDC_ST1LBT0)
	EDC_Almbit=ORA(EDC_Almbit,EDC_ST1LBT1)
	EDC_Almbit=ORA(EDC_Almbit,EDC_ST1LBT2)
	EDC_Almbit=ORA(EDC_Almbit,EDC_ST1LBT3)
	EDC_Almbit=ORA(EDC_Almbit,EDC_ST1LBT4)
	EDC_Almbit=ORA(EDC_Almbit,EDC_ST1LBT6)
	EDC_Almbit=ORA(EDC_Almbit,EDC_ST1LBT7)
	
if ANDA(getEDC1_ST1L,EDC_Almbit)<>0 then
	温度調節器1Alm=ON
else
	温度調節器1Alm=OFF
end if

if ANDA(getEDC2_ST1L,EDC_Almbit)<>0 then
	温度調節器2Alm=ON
else
	温度調節器2Alm=OFF
end if

if ANDA(getEDC3_ST1L,EDC_Almbit)<>0 then
	温度調節器3Alm=ON
else
	温度調節器3Alm=OFF
end if

if ANDA(getEDC4_ST1L,EDC_Almbit)<>0 then
	温度調節器4Alm=ON
else
	温度調節器4Alm=OFF
end if

if ANDA(getEDC5_ST1L,EDC_Almbit)<>0 then
	温度調節器5Alm=ON
else
	温度調節器5Alm=OFF
end if

if ANDA(getEDC6_ST1L,EDC_Almbit)<>0 then
	温度調節器6Alm=ON
else
	温度調節器6Alm=OFF
end if

'-----------------------------------------------------------
'拡張ユニットおよび通信エラー検出

if CR2306 then 'バッテリーエラー 交換用リチウム電池  型番 : KV-B1

end if

'-----------------------------------------------------------
'アラームリレー（CR3300～CR3415）にデバイスコメントとしてメッセージを登録
'[ファイル(F)] - CSV/TXT形式でデバイスコメントを保存
'[ファイル(F)] - CSV/TXT形式のデバイスコメントを読出

if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ0
	set(CR3300)
else
	res(CR3300)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ1
	set(CR3301)
else
	res(CR3301)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ2
	set(CR3302)
else
	res(CR3302)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ3
	set(CR3303)
else
	res(CR3303)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ4
	set(CR3304)
else
	res(CR3304)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ5
	set(CR3305)
else
	res(CR3305)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ6
	set(CR3306)
else
	res(CR3306)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ7
	set(CR3307)
else
	res(CR3307)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ8
	set(CR3308)
else
	res(CR3308)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ9
	set(CR3309)
else
	res(CR3309)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ10
	set(CR3310)
else
	res(CR3310)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ11
	set(CR3311)
else
	res(CR3311)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ12
	set(CR3312)
else
	res(CR3312)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ13
	set(CR3313)
else
	res(CR3313)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ14
	set(CR3314)
else
	res(CR3314)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ15
	set(CR3315)
else
	res(CR3315)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ16
	set(CR3400)
else
	res(CR3400)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ17
	set(CR3401)
else
	res(CR3401)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ18
	set(CR3402)
else
	res(CR3402)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ19
	set(CR3403)
else
	res(CR3403)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ20
	set(CR3404)
else
	res(CR3404)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ21
	set(CR3405)
else
	res(CR3405)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ22
	set(CR3406)
else
	res(CR3406)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ23
	set(CR3407)
else
	res(CR3407)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ24
	set(CR3408)
else
	res(CR3408)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ25
	set(CR3409)
else
	res(CR3409)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ26
	set(CR3410)
else
	res(CR3410)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ27
	set(CR3411)
else
	res(CR3411)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ28
	set(CR3412)
else
	res(CR3412)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ29
	set(CR3413)
else
	res(CR3413)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ30
	set(CR3414)
else
	res(CR3414)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ31
	set(CR3415)
else
	res(CR3415)	
end if

if 0 and CR3500 then 

end if


end if 'if systemwait.B then
'===================================================================================================================
