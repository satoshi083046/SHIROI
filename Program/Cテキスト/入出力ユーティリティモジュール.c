'入出力ユーティリティモジュール
'===================================================================================================================
'【 初期化処理 】

if CR2008 then '電源ON時初期化処理
end if
'===================================================================================================================
' inRegxxx outRegxxx
'	---------------------------------------------------------------------------------------
'	0: $1		
'	1: $2
'	2: $4
'	3: $8					加工パターン(ItemAddress)
'	4: $10
'	5: $20
'	6: $40
'	7: $80
'	----------------------------------------------------------------------------------------
'	9: $100
'	9: $200
'	10:$400					ステータスビット
'	11:$800
'	12:$1000
'	13:$2000 ほぐしA釜
'	14:$4000 ほぐしB釜
'	15:$8000 ごはん有
'	----------------------------------------------------------------------------------------

'出力コマンド	'A00000
MC4_送米ポンプ=(mMC4_送米ポンプ or ejectMC4_送米ポンプ or extMC4_送米ポンプ) and not(pauseMC4_送米ポンプ) and not(EmgMC4_送米ポンプ)	'A00009
MC5_洗米羽根=(mMC5_洗米羽根 or ejectMC5_洗米羽根 or extMC5_洗米羽根) and not(pauseMC5_洗米羽根) and not(EmgMC5_洗米羽根)	'A00010
SV1_給水電磁弁=(mSV1_給水電磁弁 or ejectSV1_給水電磁弁 or extSV1_給水電磁弁) and not(pauseSV1_給水電磁弁) and not(EmgSV1_給水電磁弁)	'A00011
SV58_洗米バルブA=(mSV58_洗米バルブA or ejectSV58_洗米バルブA or extSV58_洗米バルブA) and not(pauseSV58_洗米バルブA) and not(EmgSV58_洗米バルブA)	'A00012
MC1_張込用昇降機=(mMC1_張込用昇降機 or ejectMC1_張込用昇降機 or extMC1_張込用昇降機) and not(pauseMC1_張込用昇降機) and not(EmgMC1_張込用昇降機)	'A00065
MC2_排出用昇降機=(mMC2_排出用昇降機 or ejectMC2_排出用昇降機 or extMC2_排出用昇降機) and not(pauseMC2_排出用昇降機) and not(EmgMC2_排出用昇降機)	'A00066
MC3_計量機=(mMC3_計量機 or ejectMC3_計量機 or extMC3_計量機) and not(pauseMC3_計量機) and not(EmgMC3_計量機)	'A00067
SV12_送米切換バルブA側=(mSV12_送米切換バルブA側 or ejectSV12_送米切換バルブA側 or extSV12_送米切換バルブA側) and not(pauseSV12_送米切換バルブA側) and not(EmgSV12_送米切換バルブA側)	'A00091
SV13_送米切換バルブB側=(mSV13_送米切換バルブB側 or ejectSV13_送米切換バルブB側 or extSV13_送米切換バルブB側) and not(pauseSV13_送米切換バルブB側) and not(EmgSV13_送米切換バルブB側)	'A00092
SV2_充填バルブ開A=(mSV2_充填バルブ開A or ejectSV2_充填バルブ開A or extSV2_充填バルブ開A) and not(pauseSV2_充填バルブ開A) and not(EmgSV2_充填バルブ開A)	'A00113
SV4_水切りシャッター開A=(mSV4_水切りシャッター開A or ejectSV4_水切りシャッター開A or extSV4_水切りシャッター開A) and not(pauseSV4_水切りシャッター開A) and not(EmgSV4_水切りシャッター開A)	'A00115
SV5_水切りシャッター閉A=(mSV5_水切りシャッター閉A or ejectSV5_水切りシャッター閉A or extSV5_水切りシャッター閉A) and not(pauseSV5_水切りシャッター閉A) and not(EmgSV5_水切りシャッター閉A)	'A00116
SV6_給水電磁弁A=(mSV6_給水電磁弁A or ejectSV6_給水電磁弁A or extSV6_給水電磁弁A) and not(pauseSV6_給水電磁弁A) and not(EmgSV6_給水電磁弁A)	'A00117
SV60_排水バルブ開A=(mSV60_排水バルブ開A or ejectSV60_排水バルブ開A or extSV60_排水バルブ開A) and not(pauseSV60_排水バルブ開A) and not(EmgSV60_排水バルブ開A)	'A00122
SV7_充填バルブ開B=(mSV7_充填バルブ開B or ejectSV7_充填バルブ開B or extSV7_充填バルブ開B) and not(pauseSV7_充填バルブ開B) and not(EmgSV7_充填バルブ開B)	'A00145
SV9_水切りシャッター開B=(mSV9_水切りシャッター開B or ejectSV9_水切りシャッター開B or extSV9_水切りシャッター開B) and not(pauseSV9_水切りシャッター開B) and not(EmgSV9_水切りシャッター開B)	'A00147
SV10_水切りシャッター閉B=(mSV10_水切りシャッター閉B or ejectSV10_水切りシャッター閉B or extSV10_水切りシャッター閉B) and not(pauseSV10_水切りシャッター閉B) and not(EmgSV10_水切りシャッター閉B)	'A00148
SV11_給水電磁弁B=(mSV11_給水電磁弁B or ejectSV11_給水電磁弁B or extSV11_給水電磁弁B) and not(pauseSV11_給水電磁弁B) and not(EmgSV11_給水電磁弁B)	'A00149
SV62_排水バルブ開B=(mSV62_排水バルブ開B or ejectSV62_排水バルブ開B or extSV62_排水バルブ開B) and not(pauseSV62_排水バルブ開B) and not(EmgSV62_排水バルブ開B)	'A00154
SV17_計水タンク給水（大）=(mSV17_計水タンク給水（大） or ejectSV17_計水タンク給水（大） or extSV17_計水タンク給水（大）) and not(pauseSV17_計水タンク給水（大）) and not(EmgSV17_計水タンク給水（大）)	'A00169
SV18_計水タンク給水（小）=(mSV18_計水タンク給水（小） or ejectSV18_計水タンク給水（小） or extSV18_計水タンク給水（小）) and not(pauseSV18_計水タンク給水（小）) and not(EmgSV18_計水タンク給水（小）)	'A00170
SV19_計水電磁弁_A=(mSV19_計水電磁弁_A or ejectSV19_計水電磁弁_A or extSV19_計水電磁弁_A) and not(pauseSV19_計水電磁弁_A) and not(EmgSV19_計水電磁弁_A)	'A00171
MC6_搬送モータ=(mMC6_搬送モータ or ejectMC6_搬送モータ or extMC6_搬送モータ) and not(pauseMC6_搬送モータ) and not(EmgMC6_搬送モータ)	'A00193
MC7_搬送モータ=(mMC7_搬送モータ or ejectMC7_搬送モータ or extMC7_搬送モータ) and not(pauseMC7_搬送モータ) and not(EmgMC7_搬送モータ)	'A00194
MC8_搬送モータ=(mMC8_搬送モータ or ejectMC8_搬送モータ or extMC8_搬送モータ) and not(pauseMC8_搬送モータ) and not(EmgMC8_搬送モータ)	'A00195
MC9_モータローラ=(mMC9_モータローラ or ejectMC9_モータローラ or extMC9_モータローラ) and not(pauseMC9_モータローラ) and not(EmgMC9_モータローラ)	'A00196
SV14_ストッパ=(mSV14_ストッパ or ejectSV14_ストッパ or extSV14_ストッパ) and not(pauseSV14_ストッパ) and not(EmgSV14_ストッパ)	'A00197
SV15_ストッパ=(mSV15_ストッパ or ejectSV15_ストッパ or extSV15_ストッパ) and not(pauseSV15_ストッパ) and not(EmgSV15_ストッパ)	'A00198
SV16_リフト=(mSV16_リフト or ejectSV16_リフト or extSV16_リフト) and not(pauseSV16_リフト) and not(EmgSV16_リフト)	'A00199
MC10_反転モータ正転=(mMC10_反転モータ正転 or ejectMC10_反転モータ正転 or extMC10_反転モータ正転) and not(pauseMC10_反転モータ正転) and not(EmgMC10_反転モータ正転)	'A00233
MC10_反転モータ逆転=(mMC10_反転モータ逆転 or ejectMC10_反転モータ逆転 or extMC10_反転モータ逆転) and not(pauseMC10_反転モータ逆転) and not(EmgMC10_反転モータ逆転)	'A00234
MC32_搬送モータ=(mMC32_搬送モータ or ejectMC32_搬送モータ or extMC32_搬送モータ) and not(pauseMC32_搬送モータ) and not(EmgMC32_搬送モータ)	'A00235
MC11_搬送モータ=(mMC11_搬送モータ or ejectMC11_搬送モータ or extMC11_搬送モータ) and not(pauseMC11_搬送モータ) and not(EmgMC11_搬送モータ)	'A00265
SV20_リフト上昇=(mSV20_リフト上昇 or ejectSV20_リフト上昇 or extSV20_リフト上昇) and not(pauseSV20_リフト上昇) and not(EmgSV20_リフト上昇)	'A00266
SV100_リフト下降=(mSV100_リフト下降 or ejectSV100_リフト下降 or extSV100_リフト下降) and not(pauseSV100_リフト下降) and not(EmgSV100_リフト下降)	'A00267
MC30_搬送モータ=(mMC30_搬送モータ or ejectMC30_搬送モータ or extMC30_搬送モータ) and not(pauseMC30_搬送モータ) and not(EmgMC30_搬送モータ)	'A00281
MC12_搬送モータ=(mMC12_搬送モータ or ejectMC12_搬送モータ or extMC12_搬送モータ) and not(pauseMC12_搬送モータ) and not(EmgMC12_搬送モータ)	'A00305
MC13_搬送モータ=(mMC13_搬送モータ or ejectMC13_搬送モータ or extMC13_搬送モータ) and not(pauseMC13_搬送モータ) and not(EmgMC13_搬送モータ)	'A00306
SV21_ストッパ=(mSV21_ストッパ or ejectSV21_ストッパ or extSV21_ストッパ) and not(pauseSV21_ストッパ) and not(EmgSV21_ストッパ)	'A00309
SV22_ストッパ=(mSV22_ストッパ or ejectSV22_ストッパ or extSV22_ストッパ) and not(pauseSV22_ストッパ) and not(EmgSV22_ストッパ)	'A00310
SV23_ならし前進=(mSV23_ならし前進 or ejectSV23_ならし前進 or extSV23_ならし前進) and not(pauseSV23_ならし前進) and not(EmgSV23_ならし前進)	'A00329
SV24_ならし後退=(mSV24_ならし後退 or ejectSV24_ならし後退 or extSV24_ならし後退) and not(pauseSV24_ならし後退) and not(EmgSV24_ならし後退)	'A00330
SV25_ならし下降=(mSV25_ならし下降 or ejectSV25_ならし下降 or extSV25_ならし下降) and not(pauseSV25_ならし下降) and not(EmgSV25_ならし下降)	'A00331
SV26_ならし上昇=(mSV26_ならし上昇 or ejectSV26_ならし上昇 or extSV26_ならし上昇) and not(pauseSV26_ならし上昇) and not(EmgSV26_ならし上昇)	'A00332
SV27_ならし前進=(mSV27_ならし前進 or ejectSV27_ならし前進 or extSV27_ならし前進) and not(pauseSV27_ならし前進) and not(EmgSV27_ならし前進)	'A00333
SV28_ならし後退=(mSV28_ならし後退 or ejectSV28_ならし後退 or extSV28_ならし後退) and not(pauseSV28_ならし後退) and not(EmgSV28_ならし後退)	'A00334
MC14_搬送モータ=(mMC14_搬送モータ or ejectMC14_搬送モータ or extMC14_搬送モータ) and not(pauseMC14_搬送モータ) and not(EmgMC14_搬送モータ)	'A00385
MC15_搬送モータ=(mMC15_搬送モータ or ejectMC15_搬送モータ or extMC15_搬送モータ) and not(pauseMC15_搬送モータ) and not(EmgMC15_搬送モータ)	'A00386
MC16_モータローラ=(mMC16_モータローラ or ejectMC16_モータローラ or extMC16_モータローラ) and not(pauseMC16_モータローラ) and not(EmgMC16_モータローラ)	'A00387
SV29_ストッパ=(mSV29_ストッパ or ejectSV29_ストッパ or extSV29_ストッパ) and not(pauseSV29_ストッパ) and not(EmgSV29_ストッパ)	'A00393
SV30_ストッパ=(mSV30_ストッパ or ejectSV30_ストッパ or extSV30_ストッパ) and not(pauseSV30_ストッパ) and not(EmgSV30_ストッパ)	'A00394
SV31_クランプ=(mSV31_クランプ or ejectSV31_クランプ or extSV31_クランプ) and not(pauseSV31_クランプ) and not(EmgSV31_クランプ)	'A00395
SV32_クランプ=(mSV32_クランプ or ejectSV32_クランプ or extSV32_クランプ) and not(pauseSV32_クランプ) and not(EmgSV32_クランプ)	'A00396
SV33_リフト=(mSV33_リフト or ejectSV33_リフト or extSV33_リフト) and not(pauseSV33_リフト) and not(EmgSV33_リフト)	'A00397
SV65_ストッパ=(mSV65_ストッパ or ejectSV65_ストッパ or extSV65_ストッパ) and not(pauseSV65_ストッパ) and not(EmgSV65_ストッパ)	'A00398
SV34_シリンダ上昇A=(mSV34_シリンダ上昇A or ejectSV34_シリンダ上昇A or extSV34_シリンダ上昇A) and not(pauseSV34_シリンダ上昇A) and not(EmgSV34_シリンダ上昇A)	'A00409
SV35_シリンダ下降A=(mSV35_シリンダ下降A or ejectSV35_シリンダ下降A or extSV35_シリンダ下降A) and not(pauseSV35_シリンダ下降A) and not(EmgSV35_シリンダ下降A)	'A00410
SV36_シリンダ上昇B=(mSV36_シリンダ上昇B or ejectSV36_シリンダ上昇B or extSV36_シリンダ上昇B) and not(pauseSV36_シリンダ上昇B) and not(EmgSV36_シリンダ上昇B)	'A00411
SV37_シリンダ下降B=(mSV37_シリンダ下降B or ejectSV37_シリンダ下降B or extSV37_シリンダ下降B) and not(pauseSV37_シリンダ下降B) and not(EmgSV37_シリンダ下降B)	'A00412
SV38_クランプ=(mSV38_クランプ or ejectSV38_クランプ or extSV38_クランプ) and not(pauseSV38_クランプ) and not(EmgSV38_クランプ)	'A00413
SV39_アンクランプ=(mSV39_アンクランプ or ejectSV39_アンクランプ or extSV39_アンクランプ) and not(pauseSV39_アンクランプ) and not(EmgSV39_アンクランプ)	'A00414
SV64_釜位置=(mSV64_釜位置 or ejectSV64_釜位置 or extSV64_釜位置) and not(pauseSV64_釜位置) and not(EmgSV64_釜位置)	'A00415
MC34_釜送り正転=(mMC34_釜送り正転 or ejectMC34_釜送り正転 or extMC34_釜送り正転) and not(pauseMC34_釜送り正転) and not(EmgMC34_釜送り正転)	'A00425
MC34_釜送り逆転=(mMC34_釜送り逆転 or ejectMC34_釜送り逆転 or extMC34_釜送り逆転) and not(pauseMC34_釜送り逆転) and not(EmgMC34_釜送り逆転)	'A00426
MC43_乗移コンベア=(mMC43_乗移コンベア or ejectMC43_乗移コンベア or extMC43_乗移コンベア) and not(pauseMC43_乗移コンベア) and not(EmgMC43_乗移コンベア)	'A00427
MC18_釜送り逆転=(mMC18_釜送り逆転 or ejectMC18_釜送り逆転 or extMC18_釜送り逆転) and not(pauseMC18_釜送り逆転) and not(EmgMC18_釜送り逆転)	'A00441
MC18_釜送り正転=(mMC18_釜送り正転 or ejectMC18_釜送り正転 or extMC18_釜送り正転) and not(pauseMC18_釜送り正転) and not(EmgMC18_釜送り正転)	'A00442
MC17_むらし機モータ=(mMC17_むらし機モータ or ejectMC17_むらし機モータ or extMC17_むらし機モータ) and not(pauseMC17_むらし機モータ) and not(EmgMC17_むらし機モータ)	'A00465
MC19_搬送モータ=(mMC19_搬送モータ or ejectMC19_搬送モータ or extMC19_搬送モータ) and not(pauseMC19_搬送モータ) and not(EmgMC19_搬送モータ)	'A00513
MC20_搬送モータ=(mMC20_搬送モータ or ejectMC20_搬送モータ or extMC20_搬送モータ) and not(pauseMC20_搬送モータ) and not(EmgMC20_搬送モータ)	'A00514
MC21_搬送モータ正転=(mMC21_搬送モータ正転 or ejectMC21_搬送モータ正転 or extMC21_搬送モータ正転) and not(pauseMC21_搬送モータ正転) and not(EmgMC21_搬送モータ正転)	'A00515
MC21_搬送モータ逆転=(mMC21_搬送モータ逆転 or ejectMC21_搬送モータ逆転 or extMC21_搬送モータ逆転) and not(pauseMC21_搬送モータ逆転) and not(EmgMC21_搬送モータ逆転)	'A00516
MC22_搬送モータ正転=(mMC22_搬送モータ正転 or ejectMC22_搬送モータ正転 or extMC22_搬送モータ正転) and not(pauseMC22_搬送モータ正転) and not(EmgMC22_搬送モータ正転)	'A00517
MC22_搬送モータ逆転=(mMC22_搬送モータ逆転 or ejectMC22_搬送モータ逆転 or extMC22_搬送モータ逆転) and not(pauseMC22_搬送モータ逆転) and not(EmgMC22_搬送モータ逆転)	'A00518
MC23_モータローラ=(mMC23_モータローラ or ejectMC23_モータローラ or extMC23_モータローラ) and not(pauseMC23_モータローラ) and not(EmgMC23_モータローラ)	'A00519
SV40_ストッパ=(mSV40_ストッパ or ejectSV40_ストッパ or extSV40_ストッパ) and not(pauseSV40_ストッパ) and not(EmgSV40_ストッパ)	'A00521
SV41_リフト=(mSV41_リフト or ejectSV41_リフト or extSV41_リフト) and not(pauseSV41_リフト) and not(EmgSV41_リフト)	'A00522
SV42_ストッパ=(mSV42_ストッパ or ejectSV42_ストッパ or extSV42_ストッパ) and not(pauseSV42_ストッパ) and not(EmgSV42_ストッパ)	'A00523
SV43_ストッパ=(mSV43_ストッパ or ejectSV43_ストッパ or extSV43_ストッパ) and not(pauseSV43_ストッパ) and not(EmgSV43_ストッパ)	'A00524
SV44_リフト=(mSV44_リフト or ejectSV44_リフト or extSV44_リフト) and not(pauseSV44_リフト) and not(EmgSV44_リフト)	'A00525
SV57_バキュームリフト=(mSV57_バキュームリフト or ejectSV57_バキュームリフト or extSV57_バキュームリフト) and not(pauseSV57_バキュームリフト) and not(EmgSV57_バキュームリフト)	'A00526
SV45_シリンダ上昇A=(mSV45_シリンダ上昇A or ejectSV45_シリンダ上昇A or extSV45_シリンダ上昇A) and not(pauseSV45_シリンダ上昇A) and not(EmgSV45_シリンダ上昇A)	'A00537
SV46_シリンダ下降A=(mSV46_シリンダ下降A or ejectSV46_シリンダ下降A or extSV46_シリンダ下降A) and not(pauseSV46_シリンダ下降A) and not(EmgSV46_シリンダ下降A)	'A00538
SV47_シリンダ上昇B=(mSV47_シリンダ上昇B or ejectSV47_シリンダ上昇B or extSV47_シリンダ上昇B) and not(pauseSV47_シリンダ上昇B) and not(EmgSV47_シリンダ上昇B)	'A00539
SV48_シリンダ下降B=(mSV48_シリンダ下降B or ejectSV48_シリンダ下降B or extSV48_シリンダ下降B) and not(pauseSV48_シリンダ下降B) and not(EmgSV48_シリンダ下降B)	'A00540
SV49_アンクランプ=(mSV49_アンクランプ or ejectSV49_アンクランプ or extSV49_アンクランプ) and not(pauseSV49_アンクランプ) and not(EmgSV49_アンクランプ)	'A00541
SV50_クランプ=(mSV50_クランプ or ejectSV50_クランプ or extSV50_クランプ) and not(pauseSV50_クランプ) and not(EmgSV50_クランプ)	'A00542
MC24_吸引ポンプ=(mMC24_吸引ポンプ or ejectMC24_吸引ポンプ or extMC24_吸引ポンプ) and not(pauseMC24_吸引ポンプ) and not(EmgMC24_吸引ポンプ)	'A00569
SV51_給水電磁弁=(mSV51_給水電磁弁 or ejectSV51_給水電磁弁 or extSV51_給水電磁弁) and not(pauseSV51_給水電磁弁) and not(EmgSV51_給水電磁弁)	'A00570
SV52_シリンダ=(mSV52_シリンダ or ejectSV52_シリンダ or extSV52_シリンダ) and not(pauseSV52_シリンダ) and not(EmgSV52_シリンダ)	'A00571
MC25_搬送モータ=(mMC25_搬送モータ or ejectMC25_搬送モータ or extMC25_搬送モータ) and not(pauseMC25_搬送モータ) and not(EmgMC25_搬送モータ)	'A00577
MC26_搬送モータ=(mMC26_搬送モータ or ejectMC26_搬送モータ or extMC26_搬送モータ) and not(pauseMC26_搬送モータ) and not(EmgMC26_搬送モータ)	'A00578
SV53_ストッパ=(mSV53_ストッパ or ejectSV53_ストッパ or extSV53_ストッパ) and not(pauseSV53_ストッパ) and not(EmgSV53_ストッパ)	'A00579
SV54_ストッパ=(mSV54_ストッパ or ejectSV54_ストッパ or extSV54_ストッパ) and not(pauseSV54_ストッパ) and not(EmgSV54_ストッパ)	'A00580
MC28_搬送モータ正転=(mMC28_搬送モータ正転 or ejectMC28_搬送モータ正転 or extMC28_搬送モータ正転) and not(pauseMC28_搬送モータ正転) and not(EmgMC28_搬送モータ正転)	'A00609
MC28_搬送モータ逆転=(mMC28_搬送モータ逆転 or ejectMC28_搬送モータ逆転 or extMC28_搬送モータ逆転) and not(pauseMC28_搬送モータ逆転) and not(EmgMC28_搬送モータ逆転)	'A00610
MC29_搬送モータ正転=(mMC29_搬送モータ正転 or ejectMC29_搬送モータ正転 or extMC29_搬送モータ正転) and not(pauseMC29_搬送モータ正転) and not(EmgMC29_搬送モータ正転)	'A00611
MC29_搬送モータ逆転=(mMC29_搬送モータ逆転 or ejectMC29_搬送モータ逆転 or extMC29_搬送モータ逆転) and not(pauseMC29_搬送モータ逆転) and not(EmgMC29_搬送モータ逆転)	'A00612
MC27_モータローラ=(mMC27_モータローラ or ejectMC27_モータローラ or extMC27_モータローラ) and not(pauseMC27_モータローラ) and not(EmgMC27_モータローラ)	'A00613
SV55_リフト=(mSV55_リフト or ejectSV55_リフト or extSV55_リフト) and not(pauseSV55_リフト) and not(EmgSV55_リフト)	'A00617
SV56_ストッパ=(mSV56_ストッパ or ejectSV56_ストッパ or extSV56_ストッパ) and not(pauseSV56_ストッパ) and not(EmgSV56_ストッパ)	'A00618
MC31_反転モータ正転=(mMC31_反転モータ正転 or ejectMC31_反転モータ正転 or extMC31_反転モータ正転) and not(pauseMC31_反転モータ正転) and not(EmgMC31_反転モータ正転)	'A00633
MC31_反転モータ逆転=(mMC31_反転モータ逆転 or ejectMC31_反転モータ逆転 or extMC31_反転モータ逆転) and not(pauseMC31_反転モータ逆転) and not(EmgMC31_反転モータ逆転)	'A00634
MC33_搬送モータ=(mMC33_搬送モータ or ejectMC33_搬送モータ or extMC33_搬送モータ) and not(pauseMC33_搬送モータ) and not(EmgMC33_搬送モータ)	'A00635
SV58_シリンダ=(mSV58_シリンダ or ejectSV58_シリンダ or extSV58_シリンダ) and not(pauseSV58_シリンダ) and not(EmgSV58_シリンダ)	'A00649
MC35_洗浄ポンプA=(mMC35_洗浄ポンプA or ejectMC35_洗浄ポンプA or extMC35_洗浄ポンプA) and not(pauseMC35_洗浄ポンプA) and not(EmgMC35_洗浄ポンプA)	'A00681
MC36_洗浄ポンプB=(mMC36_洗浄ポンプB or ejectMC36_洗浄ポンプB or extMC36_洗浄ポンプB) and not(pauseMC36_洗浄ポンプB) and not(EmgMC36_洗浄ポンプB)	'A00682
MC37_洗浄ポンプC=(mMC37_洗浄ポンプC or ejectMC37_洗浄ポンプC or extMC37_洗浄ポンプC) and not(pauseMC37_洗浄ポンプC) and not(EmgMC37_洗浄ポンプC)	'A00683
MC38_洗浄ポンプD=(mMC38_洗浄ポンプD or ejectMC38_洗浄ポンプD or extMC38_洗浄ポンプD) and not(pauseMC38_洗浄ポンプD) and not(EmgMC38_洗浄ポンプD)	'A00684
MC39_洗浄ポンプE=(mMC39_洗浄ポンプE or ejectMC39_洗浄ポンプE or extMC39_洗浄ポンプE) and not(pauseMC39_洗浄ポンプE) and not(EmgMC39_洗浄ポンプE)	'A00685
MC1_インバータ用電源=(mMC1_インバータ用電源 or ejectMC1_インバータ用電源 or extMC1_インバータ用電源) and not(pauseMC1_インバータ用電源) and not(EmgMC1_インバータ用電源)	'A00686

SV67_釜フタ押さえ下降A=(mSV67_釜フタ押さえ下降A or ejectSV67_釜フタ押さえ下降A or extSV67_釜フタ押さえ下降A) and not(pauseSV67_釜フタ押さえ下降A) and not(EmgSV67_釜フタ押さえ下降A)	'A00697
SV68_釜フタ押さえ下降B=(mSV68_釜フタ押さえ下降B or ejectSV68_釜フタ押さえ下降B or extSV68_釜フタ押さえ下降B) and not(pauseSV68_釜フタ押さえ下降B) and not(EmgSV68_釜フタ押さえ下降B)	'A00698
SV69_給湯電磁弁=(mSV69_給湯電磁弁 or ejectSV69_給湯電磁弁 or extSV69_給湯電磁弁) and not(pauseSV69_給湯電磁弁) and not(EmgSV69_給湯電磁弁)	'A00699
SV70_蒸気電磁弁=(mSV70_蒸気電磁弁 or ejectSV70_蒸気電磁弁 or extSV70_蒸気電磁弁) and not(pauseSV70_蒸気電磁弁) and not(EmgSV70_蒸気電磁弁)	'A00700
SV71_釜フタストッパ=(mSV71_釜フタストッパ or ejectSV71_釜フタストッパ or extSV71_釜フタストッパ) and not(pauseSV71_釜フタストッパ) and not(EmgSV71_釜フタストッパ)	'A00701
'SV72_下洗浄電磁弁=(mSV72_下洗浄電磁弁 or ejectSV72_下洗浄電磁弁 or extSV72_下洗浄電磁弁) and not(pauseSV72_下洗浄電磁弁) and not(EmgSV72_下洗浄電磁弁)	'A00702
'SV72_下洗浄電磁弁=OFF

SV73_釜フタ押さえ下降A=(mSV73_釜フタ押さえ下降A or ejectSV73_釜フタ押さえ下降A or extSV73_釜フタ押さえ下降A) and not(pauseSV73_釜フタ押さえ下降A) and not(EmgSV73_釜フタ押さえ下降A)	'A00713
SV74_釜フタ押さえ下降B=(mSV74_釜フタ押さえ下降B or ejectSV74_釜フタ押さえ下降B or extSV74_釜フタ押さえ下降B) and not(pauseSV74_釜フタ押さえ下降B) and not(EmgSV74_釜フタ押さえ下降B)	'A00714
SV75_給湯電磁弁=(mSV75_給湯電磁弁 or ejectSV75_給湯電磁弁 or extSV75_給湯電磁弁) and not(pauseSV75_給湯電磁弁) and not(EmgSV75_給湯電磁弁)	'A00715
SV76_蒸気電磁弁=(mSV76_蒸気電磁弁 or ejectSV76_蒸気電磁弁 or extSV76_蒸気電磁弁) and not(pauseSV76_蒸気電磁弁) and not(EmgSV76_蒸気電磁弁)	'A00716
SV77_釜フタストッパ=(mSV77_釜フタストッパ or ejectSV77_釜フタストッパ or extSV77_釜フタストッパ) and not(pauseSV77_釜フタストッパ) and not(EmgSV77_釜フタストッパ)	'A00717
'SV78_下洗浄電磁弁=(mSV78_下洗浄電磁弁 or ejectSV78_下洗浄電磁弁 or extSV78_下洗浄電磁弁) and not(pauseSV78_下洗浄電磁弁) and not(EmgSV78_下洗浄電磁弁)	'A00718
'SV78_下洗浄電磁弁=OFF

SV79_釜フタ押さえ下降A=(mSV79_釜フタ押さえ下降A or ejectSV79_釜フタ押さえ下降A or extSV79_釜フタ押さえ下降A) and not(pauseSV79_釜フタ押さえ下降A) and not(EmgSV79_釜フタ押さえ下降A)	'A00729
SV80_釜フタ押さえ下降B=(mSV80_釜フタ押さえ下降B or ejectSV80_釜フタ押さえ下降B or extSV80_釜フタ押さえ下降B) and not(pauseSV80_釜フタ押さえ下降B) and not(EmgSV80_釜フタ押さえ下降B)	'A00730
SV81_給湯電磁弁=(mSV81_給湯電磁弁 or ejectSV81_給湯電磁弁 or extSV81_給湯電磁弁) and not(pauseSV81_給湯電磁弁) and not(EmgSV81_給湯電磁弁)	'A00731
SV82_蒸気電磁弁=(mSV82_蒸気電磁弁 or ejectSV82_蒸気電磁弁 or extSV82_蒸気電磁弁) and not(pauseSV82_蒸気電磁弁) and not(EmgSV82_蒸気電磁弁)	'A00732
SV83_釜フタストッパ=(mSV83_釜フタストッパ or ejectSV83_釜フタストッパ or extSV83_釜フタストッパ) and not(pauseSV83_釜フタストッパ) and not(EmgSV83_釜フタストッパ)	'A00733
'SV84_下洗浄電磁弁=(mSV84_下洗浄電磁弁 or ejectSV84_下洗浄電磁弁 or extSV84_下洗浄電磁弁) and not(pauseSV84_下洗浄電磁弁) and not(EmgSV84_下洗浄電磁弁)	'A00734
'SV84_下洗浄電磁弁=OFF

SV85_釜フタ押さえ下降A=(mSV85_釜フタ押さえ下降A or ejectSV85_釜フタ押さえ下降A or extSV85_釜フタ押さえ下降A) and not(pauseSV85_釜フタ押さえ下降A) and not(EmgSV85_釜フタ押さえ下降A)	'A00745
SV86_釜フタ押さえ下降B=(mSV86_釜フタ押さえ下降B or ejectSV86_釜フタ押さえ下降B or extSV86_釜フタ押さえ下降B) and not(pauseSV86_釜フタ押さえ下降B) and not(EmgSV86_釜フタ押さえ下降B)	'A00746
SV87_給湯電磁弁=(mSV87_給湯電磁弁 or ejectSV87_給湯電磁弁 or extSV87_給湯電磁弁) and not(pauseSV87_給湯電磁弁) and not(EmgSV87_給湯電磁弁)	'A00747
SV88_蒸気電磁弁=(mSV88_蒸気電磁弁 or ejectSV88_蒸気電磁弁 or extSV88_蒸気電磁弁) and not(pauseSV88_蒸気電磁弁) and not(EmgSV88_蒸気電磁弁)	'A00748
SV89_釜フタストッパ=(mSV89_釜フタストッパ or ejectSV89_釜フタストッパ or extSV89_釜フタストッパ) and not(pauseSV89_釜フタストッパ) and not(EmgSV89_釜フタストッパ)	'A00749
'SV90_下洗浄電磁弁=(mSV90_下洗浄電磁弁 or ejectSV90_下洗浄電磁弁 or extSV90_下洗浄電磁弁) and not(pauseSV90_下洗浄電磁弁) and not(EmgSV90_下洗浄電磁弁)	'A00750
'SV90_下洗浄電磁弁=OFF

SV91_釜フタ押さえ下降A=(mSV91_釜フタ押さえ下降A or ejectSV91_釜フタ押さえ下降A or extSV91_釜フタ押さえ下降A) and not(pauseSV91_釜フタ押さえ下降A) and not(EmgSV91_釜フタ押さえ下降A)	'A00761
SV92_釜フタ押さえ下降B=(mSV92_釜フタ押さえ下降B or ejectSV92_釜フタ押さえ下降B or extSV92_釜フタ押さえ下降B) and not(pauseSV92_釜フタ押さえ下降B) and not(EmgSV92_釜フタ押さえ下降B)	'A00762
SV93_給湯電磁弁=(mSV93_給湯電磁弁 or ejectSV93_給湯電磁弁 or extSV93_給湯電磁弁) and not(pauseSV93_給湯電磁弁) and not(EmgSV93_給湯電磁弁)	'A00763
SV94_蒸気電磁弁=(mSV94_蒸気電磁弁 or ejectSV94_蒸気電磁弁 or extSV94_蒸気電磁弁) and not(pauseSV94_蒸気電磁弁) and not(EmgSV94_蒸気電磁弁)	'A00764
SV95_釜フタストッパ=(mSV95_釜フタストッパ or ejectSV95_釜フタストッパ or extSV95_釜フタストッパ) and not(pauseSV95_釜フタストッパ) and not(EmgSV95_釜フタストッパ)	'A00765
'SV96_下洗浄電磁弁=(mSV96_下洗浄電磁弁 or ejectSV96_下洗浄電磁弁 or extSV96_下洗浄電磁弁) and not(pauseSV96_下洗浄電磁弁) and not(EmgSV96_下洗浄電磁弁)	'A00766
'SV96_下洗浄電磁弁=OFF

SV97_すすぎ電磁弁=(mSV97_すすぎ電磁弁 or ejectSV97_すすぎ電磁弁 or extSV97_すすぎ電磁弁) and not(pauseSV97_すすぎ電磁弁) and not(EmgSV97_すすぎ電磁弁)	'A00785
SV98_仕上げ電磁弁=(mSV98_仕上げ電磁弁 or ejectSV98_仕上げ電磁弁 or extSV98_仕上げ電磁弁) and not(pauseSV98_仕上げ電磁弁) and not(EmgSV98_仕上げ電磁弁)	'A00786
INV1_コンベアモータ正転=(mINV1_コンベアモータ正転 or ejectINV1_コンベアモータ正転 or extINV1_コンベアモータ正転) and not(pauseINV1_コンベアモータ正転) and not(EmgINV1_コンベアモータ正転)	'A00801
INV1_コンベア異常=(mINV1_コンベア異常 or ejectINV1_コンベア異常 or extINV1_コンベア異常) and not(pauseINV1_コンベア異常) and not(EmgINV1_コンベア異常)	'A00802
INV2_コンベアモータ正転=(mINV2_コンベアモータ正転 or ejectINV2_コンベアモータ正転 or extINV2_コンベアモータ正転) and not(pauseINV2_コンベアモータ正転) and not(EmgINV2_コンベアモータ正転)	'A00805
INV2_コンベア異常=(mINV2_コンベア異常 or ejectINV2_コンベア異常 or extINV2_コンベア異常) and not(pauseINV2_コンベア異常) and not(EmgINV2_コンベア異常)	'A00806
INV3_コンベアモータ正転=(mINV3_コンベアモータ正転 or ejectINV3_コンベアモータ正転 or extINV3_コンベアモータ正転) and not(pauseINV3_コンベアモータ正転) and not(EmgINV3_コンベアモータ正転)	'A00809
INV3_コンベア異常=(mINV3_コンベア異常 or ejectINV3_コンベア異常 or extINV3_コンベア異常) and not(pauseINV3_コンベア異常) and not(EmgINV3_コンベア異常)	'A00810
INV4_インバータ正転=(mINV4_インバータ正転 or ejectINV4_インバータ正転 or extINV4_インバータ正転) and not(pauseINV4_インバータ正転) and not(EmgINV4_インバータ正転)	'A00857
INV4_インバータ停止=(mINV4_インバータ停止 or ejectINV4_インバータ停止 or extINV4_インバータ停止) and not(pauseINV4_インバータ停止) and not(EmgINV4_インバータ停止)	'A00858
'passリレーコマンド	'B00000
passFLOS1_計量機近接センサー=pnlPBFLOS1_計量機近接センサー and passtimFLOS1_計量機近接センサー.B	'B00052
passFLOS2_洗米無洗米切換検知=pnlPBFLOS2_洗米無洗米切換検知 and passtimFLOS2_洗米無洗米切換検知.B	'B00053
passXSW9_送米切換A側=pnlPBXSW9_送米切換A側 and passtimXSW9_送米切換A側.B	'B00081
passXSW10_送米切換B側=pnlPBXSW10_送米切換B側 and passtimXSW10_送米切換B側.B	'B00082
passXSW1_充填バルブ開A=pnlPBXSW1_充填バルブ開A and passtimXSW1_充填バルブ開A.B	'B00097
passXSW2_充填バルブ閉A=pnlPBXSW2_充填バルブ閉A and passtimXSW2_充填バルブ閉A.B	'B00098
passXSW3_水切りシャッター開A=pnlPBXSW3_水切りシャッター開A and passtimXSW3_水切りシャッター開A.B	'B00099
passXSW4_水切りシャッター閉A=pnlPBXSW4_水切りシャッター閉A and passtimXSW4_水切りシャッター閉A.B	'B00100
passPDL1_パドルセンサー上限A=pnlPBPDL1_パドルセンサー上限A and passtimPDL1_パドルセンサー上限A.B	'B00106
passPDL2_パドルセンサー下限A=pnlPBPDL2_パドルセンサー下限A and passtimPDL2_パドルセンサー下限A.B	'B00107
passXSW76_排水バルブ開A=pnlPBXSW76_排水バルブ開A and passtimXSW76_排水バルブ開A.B	'B00108
passXSW77_排水バルブ閉A=pnlPBXSW77_排水バルブ閉A and passtimXSW77_排水バルブ閉A.B	'B00109
passFLOS3_LMT121=pnlPBFLOS3_LMT121 and passtimFLOS3_LMT121.B	'B00111
passXSW5_充填バルブ開B=pnlPBXSW5_充填バルブ開B and passtimXSW5_充填バルブ開B.B	'B00129
passXSW6_充填バルブ閉B=pnlPBXSW6_充填バルブ閉B and passtimXSW6_充填バルブ閉B.B	'B00130
passXSW7_水切りシャッター開B=pnlPBXSW7_水切りシャッター開B and passtimXSW7_水切りシャッター開B.B	'B00131
passXSW8_水切りシャッター閉B=pnlPBXSW8_水切りシャッター閉B and passtimXSW8_水切りシャッター閉B.B	'B00132
passPDL3_パドルセンサー上限B=pnlPBPDL3_パドルセンサー上限B and passtimPDL3_パドルセンサー上限B.B	'B00138
passPDL4_パドルセンサー下限B=pnlPBPDL4_パドルセンサー下限B and passtimPDL4_パドルセンサー下限B.B	'B00139
passXSW78_排水バルブ開B=pnlPBXSW78_排水バルブ開B and passtimXSW78_排水バルブ開B.B	'B00140
passXSW79_排水バルブ閉B=pnlPBXSW79_排水バルブ閉B and passtimXSW79_排水バルブ閉B.B	'B00141
passFLOS4_LMT121=pnlPBFLOS4_LMT121 and passtimFLOS4_LMT121.B	'B00143
passXSW106_計水バルブ開=pnlPBXSW106_計水バルブ開 and passtimXSW106_計水バルブ開.B	'B00165
passXSW107_計水バルブ閉=pnlPBXSW107_計水バルブ閉 and passtimXSW107_計水バルブ閉.B	'B00166
passXSW11_ストッパ下降端=pnlPBXSW11_ストッパ下降端 and passtimXSW11_ストッパ下降端.B	'B00181
passXSW12_ストッパ上昇端=pnlPBXSW12_ストッパ上昇端 and passtimXSW12_ストッパ上昇端.B	'B00182
passXSW13_ストッパ下降端=pnlPBXSW13_ストッパ下降端 and passtimXSW13_ストッパ下降端.B	'B00183
passXSW14_ストッパ上昇端=pnlPBXSW14_ストッパ上昇端 and passtimXSW14_ストッパ上昇端.B	'B00184
passXSW15_リフト下降端=pnlPBXSW15_リフト下降端 and passtimXSW15_リフト下降端.B	'B00185
passXSW16_リフト上昇端=pnlPBXSW16_リフト上昇端 and passtimXSW16_リフト上昇端.B	'B00186
passPH1_釜検知=pnlPBPH1_釜検知 and passtimPH1_釜検知.B	'B00187
passPH2_フタ検知=pnlPBPH2_フタ検知 and passtimPH2_フタ検知.B	'B00188
passPH3_釜検知=pnlPBPH3_釜検知 and passtimPH3_釜検知.B	'B00189
passPH4_フタ検知=pnlPBPH4_フタ検知 and passtimPH4_フタ検知.B	'B00190
passPH5_釜検知=pnlPBPH5_釜検知 and passtimPH5_釜検知.B	'B00191
passPH6_フタ検知=pnlPBPH6_フタ検知 and passtimPH6_フタ検知.B	'B00192
passPH50_釜検知=pnlPBPH50_釜検知 and passtimPH50_釜検知.B	'B00209
passPH51_フタ検知=pnlPBPH51_フタ検知 and passtimPH51_フタ検知.B	'B00210
passPH52_釜検知=pnlPBPH52_釜検知 and passtimPH52_釜検知.B	'B00211
passPH53_フタ検知=pnlPBPH53_フタ検知 and passtimPH53_フタ検知.B	'B00212
passPH7_釜検知=pnlPBPH7_釜検知 and passtimPH7_釜検知.B	'B00227
passPH8_フタ検知=pnlPBPH8_フタ検知 and passtimPH8_フタ検知.B	'B00228
passPH9_釜検知=pnlPBPH9_釜検知 and passtimPH9_釜検知.B	'B00229
passPH10_フタ検知=pnlPBPH10_フタ検知 and passtimPH10_フタ検知.B	'B00230
passLS6_空釜反転反転位置=pnlPBLS6_空釜反転反転位置 and passtimLS6_空釜反転反転位置.B	'B00231
passLS5_空釜反転原点位置=pnlPBLS5_空釜反転原点位置 and passtimLS5_空釜反転原点位置.B	'B00232
passXSW17_リフト下降端=pnlPBXSW17_リフト下降端 and passtimXSW17_リフト下降端.B	'B00258
passXSW18_リフト上昇端=pnlPBXSW18_リフト上昇端 and passtimXSW18_リフト上昇端.B	'B00259
passPH39_釜検知=pnlPBPH39_釜検知 and passtimPH39_釜検知.B	'B00260
passPH40_フタ検知=pnlPBPH40_フタ検知 and passtimPH40_フタ検知.B	'B00261
passPH41_釜検知=pnlPBPH41_釜検知 and passtimPH41_釜検知.B	'B00276
passPH42_フタ検知=pnlPBPH42_フタ検知 and passtimPH42_フタ検知.B	'B00277
passXSW19_ストッパ下降端=pnlPBXSW19_ストッパ下降端 and passtimXSW19_ストッパ下降端.B	'B00293
passXSW20_ストッパ上昇端=pnlPBXSW20_ストッパ上昇端 and passtimXSW20_ストッパ上昇端.B	'B00294
passXSW21_ストッパ下降端=pnlPBXSW21_ストッパ下降端 and passtimXSW21_ストッパ下降端.B	'B00295
passXSW22_ストッパ上昇端=pnlPBXSW22_ストッパ上昇端 and passtimXSW22_ストッパ上昇端.B	'B00296
passPH11_釜検知=pnlPBPH11_釜検知 and passtimPH11_釜検知.B	'B00297
passPH12_フタ検知=pnlPBPH12_フタ検知 and passtimPH12_フタ検知.B	'B00298
passPH13_釜検知=pnlPBPH13_釜検知 and passtimPH13_釜検知.B	'B00299
passPH14_フタ検知=pnlPBPH14_フタ検知 and passtimPH14_フタ検知.B	'B00300
passXSW23_ならし後退端=pnlPBXSW23_ならし後退端 and passtimXSW23_ならし後退端.B	'B00321
passXSW24_ならし前進端=pnlPBXSW24_ならし前進端 and passtimXSW24_ならし前進端.B	'B00322
passXSW25_ならし上昇端=pnlPBXSW25_ならし上昇端 and passtimXSW25_ならし上昇端.B	'B00323
passXSW26_ならし下降端=pnlPBXSW26_ならし下降端 and passtimXSW26_ならし下降端.B	'B00324
passXSW27_ならし後退端=pnlPBXSW27_ならし後退端 and passtimXSW27_ならし後退端.B	'B00325
passXSW28_ならし前進端=pnlPBXSW28_ならし前進端 and passtimXSW28_ならし前進端.B	'B00326
passFL001_HH_Aタンク=pnlPBFL001_HH_Aタンク and passtimFL001_HH_Aタンク.B	'B00337
passFL001_H_Aタンク=pnlPBFL001_H_Aタンク and passtimFL001_H_Aタンク.B	'B00338
passFL001_L_Aタンク=pnlPBFL001_L_Aタンク and passtimFL001_L_Aタンク.B	'B00339
passFL001_LL_Aタンク=pnlPBFL001_LL_Aタンク and passtimFL001_LL_Aタンク.B	'B00340
passFL001_HH_Bタンク=pnlPBFL001_HH_Bタンク and passtimFL001_HH_Bタンク.B	'B00341
passFL001_H_Bタンク=pnlPBFL001_H_Bタンク and passtimFL001_H_Bタンク.B	'B00342
passFL001_L_Bタンク=pnlPBFL001_L_Bタンク and passtimFL001_L_Bタンク.B	'B00343
passFL001_LL_Bタンク=pnlPBFL001_LL_Bタンク and passtimFL001_LL_Bタンク.B	'B00344
passFL001_ALMC_Aタンク=pnlPBFL001_ALMC_Aタンク and passtimFL001_ALMC_Aタンク.B	'B00345
passFL001_ALMC_Bタンク=pnlPBFL001_ALMC_Bタンク and passtimFL001_ALMC_Bタンク.B	'B00346
passXSW29_ストッパ下降端=pnlPBXSW29_ストッパ下降端 and passtimXSW29_ストッパ下降端.B	'B00357
passXSW30_ストッパ上昇端=pnlPBXSW30_ストッパ上昇端 and passtimXSW30_ストッパ上昇端.B	'B00358
passXSW31_ストッパ下降端=pnlPBXSW31_ストッパ下降端 and passtimXSW31_ストッパ下降端.B	'B00359
passXSW32_ストッパ上昇端=pnlPBXSW32_ストッパ上昇端 and passtimXSW32_ストッパ上昇端.B	'B00360
passXSW33_クランプ下降端=pnlPBXSW33_クランプ下降端 and passtimXSW33_クランプ下降端.B	'B00361
passXSW34_クランプ上昇端=pnlPBXSW34_クランプ上昇端 and passtimXSW34_クランプ上昇端.B	'B00362
passXSW35_クランプ下降端=pnlPBXSW35_クランプ下降端 and passtimXSW35_クランプ下降端.B	'B00363
passXSW36_クランプ上昇端=pnlPBXSW36_クランプ上昇端 and passtimXSW36_クランプ上昇端.B	'B00364
passXSW37_リフト下降端=pnlPBXSW37_リフト下降端 and passtimXSW37_リフト下降端.B	'B00365
passXSW38_リフト上昇端=pnlPBXSW38_リフト上昇端 and passtimXSW38_リフト上昇端.B	'B00366
passXSW74_ストッパ下降端=pnlPBXSW74_ストッパ下降端 and passtimXSW74_ストッパ下降端.B	'B00367
passXSW75_ストッパ上昇端=pnlPBXSW75_ストッパ上昇端 and passtimXSW75_ストッパ上昇端.B	'B00368
passPH15_釜検知=pnlPBPH15_釜検知 and passtimPH15_釜検知.B	'B00369
passPH16_フタ検知=pnlPBPH16_フタ検知 and passtimPH16_フタ検知.B	'B00370
passPH17_釜検知=pnlPBPH17_釜検知 and passtimPH17_釜検知.B	'B00371
passPH18_フタ検知=pnlPBPH18_フタ検知 and passtimPH18_フタ検知.B	'B00372
passPH19_釜検知=pnlPBPH19_釜検知 and passtimPH19_釜検知.B	'B00373
passPH20_フタ検知=pnlPBPH20_フタ検知 and passtimPH20_フタ検知.B	'B00374
passXSW39_シリンダ上昇端A=pnlPBXSW39_シリンダ上昇端A and passtimXSW39_シリンダ上昇端A.B	'B00401
passXSW40_シリンダ下降端A=pnlPBXSW40_シリンダ下降端A and passtimXSW40_シリンダ下降端A.B	'B00402
passXSW41_シリンダ上昇端B=pnlPBXSW41_シリンダ上昇端B and passtimXSW41_シリンダ上昇端B.B	'B00403
passXSW42_シリンダ下降端B=pnlPBXSW42_シリンダ下降端B and passtimXSW42_シリンダ下降端B.B	'B00404
passXSW43_クランプ=pnlPBXSW43_クランプ and passtimXSW43_クランプ.B	'B00405
passXSW44_アンクランプ=pnlPBXSW44_アンクランプ and passtimXSW44_アンクランプ.B	'B00406
passXSW111_釜位置右後退端=pnlPBXSW111_釜位置右後退端 and passtimXSW111_釜位置右後退端.B	'B00407
passXSW112_釜位置左後退端=pnlPBXSW112_釜位置左後退端 and passtimXSW112_釜位置左後退端.B	'B00408
passLS9_釜送り前進端=pnlPBLS9_釜送り前進端 and passtimLS9_釜送り前進端.B	'B00418
passLS10_釜送り後退端=pnlPBLS10_釜送り後退端 and passtimLS10_釜送り後退端.B	'B00419
passPH54_釜送りトリガ=pnlPBPH54_釜送りトリガ and passtimPH54_釜送りトリガ.B	'B00420
passPH55_釜検知ステージ=pnlPBPH55_釜検知ステージ and passtimPH55_釜検知ステージ.B	'B00421
passPH58_釜検知前ステージ=pnlPBPH58_釜検知前ステージ and passtimPH58_釜検知前ステージ.B	'B00422
passPH59_釜検知炊飯機入口=pnlPBPH59_釜検知炊飯機入口 and passtimPH59_釜検知炊飯機入口.B	'B00423
passLS1_釜送り前進端=pnlPBLS1_釜送り前進端 and passtimLS1_釜送り前進端.B	'B00434
passLS2_釜送り後退端=pnlPBLS2_釜送り後退端 and passtimLS2_釜送り後退端.B	'B00435
passPH56_釜送りトリガ=pnlPBPH56_釜送りトリガ and passtimPH56_釜送りトリガ.B	'B00436
passPH57_釜検知ステージ=pnlPBPH57_釜検知ステージ and passtimPH57_釜検知ステージ.B	'B00437
passLS3_むらし機ピッチ検知=pnlPBLS3_むらし機ピッチ検知 and passtimLS3_むらし機ピッチ検知.B	'B00459
passPH21_むらし機出口センサ=pnlPBPH21_むらし機出口センサ and passtimPH21_むらし機出口センサ.B	'B00461
passLS31_むらし機入口センサ=pnlPBLS31_むらし機入口センサ and passtimLS31_むらし機入口センサ.B	'B00463
passXSW45_ストッパ下降端=pnlPBXSW45_ストッパ下降端 and passtimXSW45_ストッパ下降端.B	'B00489
passXSW46_ストッパ上昇端=pnlPBXSW46_ストッパ上昇端 and passtimXSW46_ストッパ上昇端.B	'B00490
passXSW47_リフト下降端=pnlPBXSW47_リフト下降端 and passtimXSW47_リフト下降端.B	'B00491
passXSW48_リフト上昇端=pnlPBXSW48_リフト上昇端 and passtimXSW48_リフト上昇端.B	'B00492
passXSW49_ストッパ下降端=pnlPBXSW49_ストッパ下降端 and passtimXSW49_ストッパ下降端.B	'B00493
passXSW50_ストッパ上昇端=pnlPBXSW50_ストッパ上昇端 and passtimXSW50_ストッパ上昇端.B	'B00494
passXSW51_ストッパ下降端=pnlPBXSW51_ストッパ下降端 and passtimXSW51_ストッパ下降端.B	'B00495
passXSW52_ストッパ上昇端=pnlPBXSW52_ストッパ上昇端 and passtimXSW52_ストッパ上昇端.B	'B00496
passXSW53_リフト下降端=pnlPBXSW53_リフト下降端 and passtimXSW53_リフト下降端.B	'B00497
passXSW54_リフト上昇端=pnlPBXSW54_リフト上昇端 and passtimXSW54_リフト上昇端.B	'B00498
passXSW71_バキューマリフト下降端=pnlPBXSW71_バキューマリフト下降端 and passtimXSW71_バキューマリフト下降端.B	'B00499
passXSW72_バキューマリフト上昇端=pnlPBXSW72_バキューマリフト上昇端 and passtimXSW72_バキューマリフト上昇端.B	'B00500
passPH22_釜検知=pnlPBPH22_釜検知 and passtimPH22_釜検知.B	'B00501
passPH23_釜検知=pnlPBPH23_釜検知 and passtimPH23_釜検知.B	'B00503
passPH24_フタ検知=pnlPBPH24_フタ検知 and passtimPH24_フタ検知.B	'B00504
passPH25_釜検知=pnlPBPH25_釜検知 and passtimPH25_釜検知.B	'B00505
passPH26_フタ検知=pnlPBPH26_フタ検知 and passtimPH26_フタ検知.B	'B00506
passPH27_釜検知=pnlPBPH27_釜検知 and passtimPH27_釜検知.B	'B00507
passPH28_フタ検知=pnlPBPH28_フタ検知 and passtimPH28_フタ検知.B	'B00508
passPH29_釜検知=pnlPBPH29_釜検知 and passtimPH29_釜検知.B	'B00509
passPH30_フタ検知=pnlPBPH30_フタ検知 and passtimPH30_フタ検知.B	'B00510
passPH31_釜検知=pnlPBPH31_釜検知 and passtimPH31_釜検知.B	'B00511
passXSW55_シリンダ上昇端A=pnlPBXSW55_シリンダ上昇端A and passtimXSW55_シリンダ上昇端A.B	'B00529
passXSW56_シリンダ下降端A=pnlPBXSW56_シリンダ下降端A and passtimXSW56_シリンダ下降端A.B	'B00530
passXSW57_シリンダ上昇端B=pnlPBXSW57_シリンダ上昇端B and passtimXSW57_シリンダ上昇端B.B	'B00531
passXSW58_シリンダ下降端B=pnlPBXSW58_シリンダ下降端B and passtimXSW58_シリンダ下降端B.B	'B00532
passXSW59_アンクランプ=pnlPBXSW59_アンクランプ and passtimXSW59_アンクランプ.B	'B00533
passXSW60_クランプ=pnlPBXSW60_クランプ and passtimXSW60_クランプ.B	'B00534
passXSW63_ストッパ下降端=pnlPBXSW63_ストッパ下降端 and passtimXSW63_ストッパ下降端.B	'B00549
passXSW64_ストッパ上昇端=pnlPBXSW64_ストッパ上昇端 and passtimXSW64_ストッパ上昇端.B	'B00550
passXSW65_ストッパ下降端=pnlPBXSW65_ストッパ下降端 and passtimXSW65_ストッパ下降端.B	'B00551
passXSW66_ストッパ上昇端=pnlPBXSW66_ストッパ上昇端 and passtimXSW66_ストッパ上昇端.B	'B00552
passPH32_釜検知=pnlPBPH32_釜検知 and passtimPH32_釜検知.B	'B00553
passPH33_フタ検知=pnlPBPH33_フタ検知 and passtimPH33_フタ検知.B	'B00554
passPH34_釜検知=pnlPBPH34_釜検知 and passtimPH34_釜検知.B	'B00555
passPH35_フタ検知=pnlPBPH35_フタ検知 and passtimPH35_フタ検知.B	'B00556
passXSW61_シリンダ上昇端=pnlPBXSW61_シリンダ上昇端 and passtimXSW61_シリンダ上昇端.B	'B00562
passXSW62_シリンダ下降端=pnlPBXSW62_シリンダ下降端 and passtimXSW62_シリンダ下降端.B	'B00563
passXSW67_リフト下降端=pnlPBXSW67_リフト下降端 and passtimXSW67_リフト下降端.B	'B00597
passXSW68_リフト上昇端=pnlPBXSW68_リフト上昇端 and passtimXSW68_リフト上昇端.B	'B00598
passXSW69_ストッパ下降端=pnlPBXSW69_ストッパ下降端 and passtimXSW69_ストッパ下降端.B	'B00599
passXSW70_ストッパ上昇端=pnlPBXSW70_ストッパ上昇端 and passtimXSW70_ストッパ上昇端.B	'B00600
passPH36_釜検知=pnlPBPH36_釜検知 and passtimPH36_釜検知.B	'B00601
passPH37_フタ検知=pnlPBPH37_フタ検知 and passtimPH37_フタ検知.B	'B00602
passPH48_釜検知=pnlPBPH48_釜検知 and passtimPH48_釜検知.B	'B00603
passPH49_フタ検知=pnlPBPH49_フタ検知 and passtimPH49_フタ検知.B	'B00604
passPH38_釜検知=pnlPBPH38_釜検知 and passtimPH38_釜検知.B	'B00605
passPH43_釜検知=pnlPBPH43_釜検知 and passtimPH43_釜検知.B	'B00627
passPH44_フタ検知=pnlPBPH44_フタ検知 and passtimPH44_フタ検知.B	'B00628
passPH45_釜検知=pnlPBPH45_釜検知 and passtimPH45_釜検知.B	'B00629
passPH46_フタ検知=pnlPBPH46_フタ検知 and passtimPH46_フタ検知.B	'B00630
passLS7_釜反転機原点位置=pnlPBLS7_釜反転機原点位置 and passtimLS7_釜反転機原点位置.B	'B00631
passLS8_釜反転機反転位置=pnlPBLS8_釜反転機反転位置 and passtimLS8_釜反転機反転位置.B	'B00632
passXSW73_シリンダ上昇端=pnlPBXSW73_シリンダ上昇端 and passtimXSW73_シリンダ上昇端.B	'B00641
passXSW80_シリンダ下降端=pnlPBXSW80_シリンダ下降端 and passtimXSW80_シリンダ下降端.B	'B00642
passXSW83_釜フタ押さえ上昇端B=pnlPBXSW83_釜フタ押さえ上昇端B and passtimXSW83_釜フタ押さえ上昇端B.B	'B00689
passXSW84_釜フタ押さえ下降端B=pnlPBXSW84_釜フタ押さえ下降端B and passtimXSW84_釜フタ押さえ下降端B.B	'B00690
passXSW81_釜フタ押さえ上昇端A=pnlPBXSW81_釜フタ押さえ上昇端A and passtimXSW81_釜フタ押さえ上昇端A.B	'B00691
passXSW82_釜フタ押さえ下降端A=pnlPBXSW82_釜フタ押さえ下降端A and passtimXSW82_釜フタ押さえ下降端A.B	'B00692
passXSW85_釜フタストッパ下降端=pnlPBXSW85_釜フタストッパ下降端 and passtimXSW85_釜フタストッパ下降端.B	'B00693
'passLS11_釜フタ検知=pnlPBLS11_釜フタ検知 and passtimLS11_釜フタ検知.B	'B00694
passFLT1_タンク上限=pnlPBFLT1_タンク上限 and passtimFLT1_タンク上限.B	'B00695
passFLT2_タンク下限=pnlPBFLT2_タンク下限 and passtimFLT2_タンク下限.B	'B00696
passXSW88_釜フタ押さえ上昇端B=pnlPBXSW88_釜フタ押さえ上昇端B and passtimXSW88_釜フタ押さえ上昇端B.B	'B00705
passXSW89_釜フタ押さえ下降端B=pnlPBXSW89_釜フタ押さえ下降端B and passtimXSW89_釜フタ押さえ下降端B.B	'B00706
passXSW86_釜フタ押さえ上昇端A=pnlPBXSW86_釜フタ押さえ上昇端A and passtimXSW86_釜フタ押さえ上昇端A.B	'B00707
passXSW87_釜フタ押さえ下降端A=pnlPBXSW87_釜フタ押さえ下降端A and passtimXSW87_釜フタ押さえ下降端A.B	'B00708
passXSW90_釜フタストッパ下降端=pnlPBXSW90_釜フタストッパ下降端 and passtimXSW90_釜フタストッパ下降端.B	'B00709
'passLS12_釜フタ検知=pnlPBLS12_釜フタ検知 and passtimLS12_釜フタ検知.B	'B00710
passFLT3_タンク上限=pnlPBFLT3_タンク上限 and passtimFLT3_タンク上限.B	'B00711
passFLT4_タンク下限=pnlPBFLT4_タンク下限 and passtimFLT4_タンク下限.B	'B00712
passXSW93_釜フタ押さえ上昇端B=pnlPBXSW93_釜フタ押さえ上昇端B and passtimXSW93_釜フタ押さえ上昇端B.B	'B00721
passXSW94_釜フタ押さえ下降端B=pnlPBXSW94_釜フタ押さえ下降端B and passtimXSW94_釜フタ押さえ下降端B.B	'B00722
passXSW91_釜フタ押さえ上昇端A=pnlPBXSW91_釜フタ押さえ上昇端A and passtimXSW91_釜フタ押さえ上昇端A.B	'B00723
passXSW92_釜フタ押さえ下降端A=pnlPBXSW92_釜フタ押さえ下降端A and passtimXSW92_釜フタ押さえ下降端A.B	'B00724
passXSW95_釜フタストッパ下降端=pnlPBXSW95_釜フタストッパ下降端 and passtimXSW95_釜フタストッパ下降端.B	'B00725
'passLS13_釜フタ検知=pnlPBLS13_釜フタ検知 and passtimLS13_釜フタ検知.B	'B00726
passFLT5_タンク上限=pnlPBFLT5_タンク上限 and passtimFLT5_タンク上限.B	'B00727
passFLT6_タンク下限=pnlPBFLT6_タンク下限 and passtimFLT6_タンク下限.B	'B00728
passXSW98_釜フタ押さえ上昇端B=pnlPBXSW98_釜フタ押さえ上昇端B and passtimXSW98_釜フタ押さえ上昇端B.B	'B00737
passXSW99_釜フタ押さえ下降端B=pnlPBXSW99_釜フタ押さえ下降端B and passtimXSW99_釜フタ押さえ下降端B.B	'B00738
passXSW96_釜フタ押さえ上昇端A=pnlPBXSW96_釜フタ押さえ上昇端A and passtimXSW96_釜フタ押さえ上昇端A.B	'B00739
passXSW97_釜フタ押さえ下降端A=pnlPBXSW97_釜フタ押さえ下降端A and passtimXSW97_釜フタ押さえ下降端A.B	'B00740
passXSW100_釜フタストッパ下降端=pnlPBXSW100_釜フタストッパ下降端 and passtimXSW100_釜フタストッパ下降端.B	'B00741
'passLS14_釜フタ検知=pnlPBLS14_釜フタ検知 and passtimLS14_釜フタ検知.B	'B00742
passFLT7_タンク上限=pnlPBFLT7_タンク上限 and passtimFLT7_タンク上限.B	'B00743
passFLT8_タンク下限=pnlPBFLT8_タンク下限 and passtimFLT8_タンク下限.B	'B00744
passXSW103_釜フタ押さえ上昇端B=pnlPBXSW103_釜フタ押さえ上昇端B and passtimXSW103_釜フタ押さえ上昇端B.B	'B00753
passXSW104_釜フタ押さえ下降端B=pnlPBXSW104_釜フタ押さえ下降端B and passtimXSW104_釜フタ押さえ下降端B.B	'B00754
passXSW101_釜フタ押さえ上昇端A=pnlPBXSW101_釜フタ押さえ上昇端A and passtimXSW101_釜フタ押さえ上昇端A.B	'B00755
passXSW102_釜フタ押さえ下降端A=pnlPBXSW102_釜フタ押さえ下降端A and passtimXSW102_釜フタ押さえ下降端A.B	'B00756
passXSW105_釜フタストッパ下降端=pnlPBXSW105_釜フタストッパ下降端 and passtimXSW105_釜フタストッパ下降端.B	'B00757
'passLS15_釜フタ検知=pnlPBLS15_釜フタ検知 and passtimLS15_釜フタ検知.B	'B00758
passFLT9_タンク上限=pnlPBFLT9_タンク上限 and passtimFLT9_タンク上限.B	'B00759
passFLT10_タンク下限=pnlPBFLT10_タンク下限 and passtimFLT10_タンク下限.B	'B00760
'Latchリレーコマンド	'C00000
LatchFLOS1_計量機近接センサー=LatchFLOS1_計量機近接センサー or FLOS1_計量機近接センサー	'C00052
LatchFLOS2_洗米無洗米切換検知=LatchFLOS2_洗米無洗米切換検知 or FLOS2_洗米無洗米切換検知	'C00053
LatchXSW9_送米切換A側=LatchXSW9_送米切換A側 or XSW9_送米切換A側	'C00081
LatchXSW10_送米切換B側=LatchXSW10_送米切換B側 or XSW10_送米切換B側	'C00082
LatchXSW1_充填バルブ開A=LatchXSW1_充填バルブ開A or XSW1_充填バルブ開A	'C00097
LatchXSW2_充填バルブ閉A=LatchXSW2_充填バルブ閉A or XSW2_充填バルブ閉A	'C00098
LatchXSW3_水切りシャッター開A=LatchXSW3_水切りシャッター開A or XSW3_水切りシャッター開A	'C00099
LatchXSW4_水切りシャッター閉A=LatchXSW4_水切りシャッター閉A or XSW4_水切りシャッター閉A	'C00100
LatchPDL1_パドルセンサー上限A=LatchPDL1_パドルセンサー上限A or PDL1_パドルセンサー上限A	'C00106
LatchPDL2_パドルセンサー下限A=LatchPDL2_パドルセンサー下限A or PDL2_パドルセンサー下限A	'C00107
LatchXSW76_排水バルブ開A=LatchXSW76_排水バルブ開A or XSW76_排水バルブ開A	'C00108
LatchXSW77_排水バルブ閉A=LatchXSW77_排水バルブ閉A or XSW77_排水バルブ閉A	'C00109
LatchFLOS3_LMT121=LatchFLOS3_LMT121 or FLOS3_LMT121	'C00111
LatchXSW5_充填バルブ開B=LatchXSW5_充填バルブ開B or XSW5_充填バルブ開B	'C00129
LatchXSW6_充填バルブ閉B=LatchXSW6_充填バルブ閉B or XSW6_充填バルブ閉B	'C00130
LatchXSW7_水切りシャッター開B=LatchXSW7_水切りシャッター開B or XSW7_水切りシャッター開B	'C00131
LatchXSW8_水切りシャッター閉B=LatchXSW8_水切りシャッター閉B or XSW8_水切りシャッター閉B	'C00132
LatchPDL3_パドルセンサー上限B=LatchPDL3_パドルセンサー上限B or PDL3_パドルセンサー上限B	'C00138
LatchPDL4_パドルセンサー下限B=LatchPDL4_パドルセンサー下限B or PDL4_パドルセンサー下限B	'C00139
LatchXSW78_排水バルブ開B=LatchXSW78_排水バルブ開B or XSW78_排水バルブ開B	'C00140
LatchXSW79_排水バルブ閉B=LatchXSW79_排水バルブ閉B or XSW79_排水バルブ閉B	'C00141
LatchFLOS4_LMT121=LatchFLOS4_LMT121 or FLOS4_LMT121	'C00143
LatchXSW106_計水バルブ開=LatchXSW106_計水バルブ開 or XSW106_計水バルブ開	'C00165
LatchXSW107_計水バルブ閉=LatchXSW107_計水バルブ閉 or XSW107_計水バルブ閉	'C00166
LatchXSW11_ストッパ下降端=LatchXSW11_ストッパ下降端 or XSW11_ストッパ下降端	'C00181
LatchXSW12_ストッパ上昇端=LatchXSW12_ストッパ上昇端 or XSW12_ストッパ上昇端	'C00182
LatchXSW13_ストッパ下降端=LatchXSW13_ストッパ下降端 or XSW13_ストッパ下降端	'C00183
LatchXSW14_ストッパ上昇端=LatchXSW14_ストッパ上昇端 or XSW14_ストッパ上昇端	'C00184
LatchXSW15_リフト下降端=LatchXSW15_リフト下降端 or XSW15_リフト下降端	'C00185
LatchXSW16_リフト上昇端=LatchXSW16_リフト上昇端 or XSW16_リフト上昇端	'C00186
LatchPH1_釜検知=LatchPH1_釜検知 or PH1_釜検知	'C00187
LatchPH2_フタ検知=LatchPH2_フタ検知 or PH2_フタ検知	'C00188
LatchPH3_釜検知=LatchPH3_釜検知 or PH3_釜検知	'C00189
LatchPH4_フタ検知=LatchPH4_フタ検知 or PH4_フタ検知	'C00190
LatchPH5_釜検知=LatchPH5_釜検知 or PH5_釜検知	'C00191
LatchPH6_フタ検知=LatchPH6_フタ検知 or PH6_フタ検知	'C00192
LatchPH50_釜検知=LatchPH50_釜検知 or PH50_釜検知	'C00209
LatchPH51_フタ検知=LatchPH51_フタ検知 or PH51_フタ検知	'C00210
LatchPH52_釜検知=LatchPH52_釜検知 or PH52_釜検知	'C00211
LatchPH53_フタ検知=LatchPH53_フタ検知 or PH53_フタ検知	'C00212
LatchPH7_釜検知=LatchPH7_釜検知 or PH7_釜検知	'C00227
LatchPH8_フタ検知=LatchPH8_フタ検知 or PH8_フタ検知	'C00228
LatchPH9_釜検知=LatchPH9_釜検知 or PH9_釜検知	'C00229
LatchPH10_フタ検知=LatchPH10_フタ検知 or PH10_フタ検知	'C00230
LatchLS6_空釜反転反転位置=LatchLS6_空釜反転反転位置 or LS6_空釜反転反転位置	'C00231
LatchLS5_空釜反転原点位置=LatchLS5_空釜反転原点位置 or LS5_空釜反転原点位置	'C00232
LatchXSW17_リフト下降端=LatchXSW17_リフト下降端 or XSW17_リフト下降端	'C00258
LatchXSW18_リフト上昇端=LatchXSW18_リフト上昇端 or XSW18_リフト上昇端	'C00259
LatchPH39_釜検知=LatchPH39_釜検知 or PH39_釜検知	'C00260
LatchPH40_フタ検知=LatchPH40_フタ検知 or PH40_フタ検知	'C00261
LatchPH41_釜検知=LatchPH41_釜検知 or PH41_釜検知	'C00276
LatchPH42_フタ検知=LatchPH42_フタ検知 or PH42_フタ検知	'C00277
LatchXSW19_ストッパ下降端=LatchXSW19_ストッパ下降端 or XSW19_ストッパ下降端	'C00293
LatchXSW20_ストッパ上昇端=LatchXSW20_ストッパ上昇端 or XSW20_ストッパ上昇端	'C00294
LatchXSW21_ストッパ下降端=LatchXSW21_ストッパ下降端 or XSW21_ストッパ下降端	'C00295
LatchXSW22_ストッパ上昇端=LatchXSW22_ストッパ上昇端 or XSW22_ストッパ上昇端	'C00296
LatchPH11_釜検知=LatchPH11_釜検知 or PH11_釜検知	'C00297
LatchPH12_フタ検知=LatchPH12_フタ検知 or PH12_フタ検知	'C00298
LatchPH13_釜検知=LatchPH13_釜検知 or PH13_釜検知	'C00299
LatchPH14_フタ検知=LatchPH14_フタ検知 or PH14_フタ検知	'C00300
LatchXSW23_ならし後退端=LatchXSW23_ならし後退端 or XSW23_ならし後退端	'C00321
LatchXSW24_ならし前進端=LatchXSW24_ならし前進端 or XSW24_ならし前進端	'C00322
LatchXSW25_ならし上昇端=LatchXSW25_ならし上昇端 or XSW25_ならし上昇端	'C00323
LatchXSW26_ならし下降端=LatchXSW26_ならし下降端 or XSW26_ならし下降端	'C00324
LatchXSW27_ならし後退端=LatchXSW27_ならし後退端 or XSW27_ならし後退端	'C00325
LatchXSW28_ならし前進端=LatchXSW28_ならし前進端 or XSW28_ならし前進端	'C00326
LatchFL001_HH_Aタンク=LatchFL001_HH_Aタンク or FL001_HH_Aタンク	'C00337
LatchFL001_H_Aタンク=LatchFL001_H_Aタンク or FL001_H_Aタンク	'C00338
LatchFL001_L_Aタンク=LatchFL001_L_Aタンク or FL001_L_Aタンク	'C00339
LatchFL001_LL_Aタンク=LatchFL001_LL_Aタンク or FL001_LL_Aタンク	'C00340
LatchFL001_HH_Bタンク=LatchFL001_HH_Bタンク or FL001_HH_Bタンク	'C00341
LatchFL001_H_Bタンク=LatchFL001_H_Bタンク or FL001_H_Bタンク	'C00342
LatchFL001_L_Bタンク=LatchFL001_L_Bタンク or FL001_L_Bタンク	'C00343
LatchFL001_LL_Bタンク=LatchFL001_LL_Bタンク or FL001_LL_Bタンク	'C00344
LatchFL001_ALMC_Aタンク=LatchFL001_ALMC_Aタンク or FL001_ALMC_Aタンク	'C00345
LatchFL001_ALMC_Bタンク=LatchFL001_ALMC_Bタンク or FL001_ALMC_Bタンク	'C00346
LatchXSW29_ストッパ下降端=LatchXSW29_ストッパ下降端 or XSW29_ストッパ下降端	'C00357
LatchXSW30_ストッパ上昇端=LatchXSW30_ストッパ上昇端 or XSW30_ストッパ上昇端	'C00358
LatchXSW31_ストッパ下降端=LatchXSW31_ストッパ下降端 or XSW31_ストッパ下降端	'C00359
LatchXSW32_ストッパ上昇端=LatchXSW32_ストッパ上昇端 or XSW32_ストッパ上昇端	'C00360
LatchXSW33_クランプ下降端=LatchXSW33_クランプ下降端 or XSW33_クランプ下降端	'C00361
LatchXSW34_クランプ上昇端=LatchXSW34_クランプ上昇端 or XSW34_クランプ上昇端	'C00362
LatchXSW35_クランプ下降端=LatchXSW35_クランプ下降端 or XSW35_クランプ下降端	'C00363
LatchXSW36_クランプ上昇端=LatchXSW36_クランプ上昇端 or XSW36_クランプ上昇端	'C00364
LatchXSW37_リフト下降端=LatchXSW37_リフト下降端 or XSW37_リフト下降端	'C00365
LatchXSW38_リフト上昇端=LatchXSW38_リフト上昇端 or XSW38_リフト上昇端	'C00366
LatchXSW74_ストッパ下降端=LatchXSW74_ストッパ下降端 or XSW74_ストッパ下降端	'C00367
LatchXSW75_ストッパ上昇端=LatchXSW75_ストッパ上昇端 or XSW75_ストッパ上昇端	'C00368
LatchPH15_釜検知=LatchPH15_釜検知 or PH15_釜検知	'C00369
LatchPH16_フタ検知=LatchPH16_フタ検知 or PH16_フタ検知	'C00370
LatchPH17_釜検知=LatchPH17_釜検知 or PH17_釜検知	'C00371
LatchPH18_フタ検知=LatchPH18_フタ検知 or PH18_フタ検知	'C00372
LatchPH19_釜検知=LatchPH19_釜検知 or PH19_釜検知	'C00373
LatchPH20_フタ検知=LatchPH20_フタ検知 or PH20_フタ検知	'C00374
LatchXSW39_シリンダ上昇端A=LatchXSW39_シリンダ上昇端A or XSW39_シリンダ上昇端A	'C00401
LatchXSW40_シリンダ下降端A=LatchXSW40_シリンダ下降端A or XSW40_シリンダ下降端A	'C00402
LatchXSW41_シリンダ上昇端B=LatchXSW41_シリンダ上昇端B or XSW41_シリンダ上昇端B	'C00403
LatchXSW42_シリンダ下降端B=LatchXSW42_シリンダ下降端B or XSW42_シリンダ下降端B	'C00404
LatchXSW43_クランプ=LatchXSW43_クランプ or XSW43_クランプ	'C00405
LatchXSW44_アンクランプ=LatchXSW44_アンクランプ or XSW44_アンクランプ	'C00406
LatchXSW111_釜位置右後退端=LatchXSW111_釜位置右後退端 or XSW111_釜位置右後退端	'C00407
LatchXSW112_釜位置左後退端=LatchXSW112_釜位置左後退端 or XSW112_釜位置左後退端	'C00408
LatchLS9_釜送り前進端=LatchLS9_釜送り前進端 or LS9_釜送り前進端	'C00418
LatchLS10_釜送り後退端=LatchLS10_釜送り後退端 or LS10_釜送り後退端	'C00419
LatchPH54_釜送りトリガ=LatchPH54_釜送りトリガ or PH54_釜送りトリガ	'C00420
LatchPH55_釜検知ステージ=LatchPH55_釜検知ステージ or PH55_釜検知ステージ	'C00421
LatchPH58_釜検知前ステージ=LatchPH58_釜検知前ステージ or PH58_釜検知前ステージ	'C00422
LatchPH59_釜検知炊飯機入口=LatchPH59_釜検知炊飯機入口 or PH59_釜検知炊飯機入口	'C00423
LatchLS1_釜送り前進端=LatchLS1_釜送り前進端 or LS1_釜送り前進端	'C00434
LatchLS2_釜送り後退端=LatchLS2_釜送り後退端 or LS2_釜送り後退端	'C00435
LatchPH56_釜送りトリガ=LatchPH56_釜送りトリガ or PH56_釜送りトリガ	'C00436
LatchPH57_釜検知ステージ=LatchPH57_釜検知ステージ or PH57_釜検知ステージ	'C00437
LatchLS3_むらし機ピッチ検知=LatchLS3_むらし機ピッチ検知 or LS3_むらし機ピッチ検知	'C00459
LatchPH21_むらし機出口センサ=LatchPH21_むらし機出口センサ or PH21_むらし機出口センサ	'C00461
LatchLS31_むらし機入口センサ=LatchLS31_むらし機入口センサ or LS31_むらし機入口センサ	'C00463
LatchXSW45_ストッパ下降端=LatchXSW45_ストッパ下降端 or XSW45_ストッパ下降端	'C00489
LatchXSW46_ストッパ上昇端=LatchXSW46_ストッパ上昇端 or XSW46_ストッパ上昇端	'C00490
LatchXSW47_リフト下降端=LatchXSW47_リフト下降端 or XSW47_リフト下降端	'C00491
LatchXSW48_リフト上昇端=LatchXSW48_リフト上昇端 or XSW48_リフト上昇端	'C00492
LatchXSW49_ストッパ下降端=LatchXSW49_ストッパ下降端 or XSW49_ストッパ下降端	'C00493
LatchXSW50_ストッパ上昇端=LatchXSW50_ストッパ上昇端 or XSW50_ストッパ上昇端	'C00494
LatchXSW51_ストッパ下降端=LatchXSW51_ストッパ下降端 or XSW51_ストッパ下降端	'C00495
LatchXSW52_ストッパ上昇端=LatchXSW52_ストッパ上昇端 or XSW52_ストッパ上昇端	'C00496
LatchXSW53_リフト下降端=LatchXSW53_リフト下降端 or XSW53_リフト下降端	'C00497
LatchXSW54_リフト上昇端=LatchXSW54_リフト上昇端 or XSW54_リフト上昇端	'C00498
LatchXSW71_バキューマリフト下降端=LatchXSW71_バキューマリフト下降端 or XSW71_バキューマリフト下降端	'C00499
LatchXSW72_バキューマリフト上昇端=LatchXSW72_バキューマリフト上昇端 or XSW72_バキューマリフト上昇端	'C00500
LatchPH22_釜検知=LatchPH22_釜検知 or PH22_釜検知	'C00501
LatchPH23_釜検知=LatchPH23_釜検知 or PH23_釜検知	'C00503
LatchPH24_フタ検知=LatchPH24_フタ検知 or PH24_フタ検知	'C00504
LatchPH25_釜検知=LatchPH25_釜検知 or PH25_釜検知	'C00505
LatchPH26_フタ検知=LatchPH26_フタ検知 or PH26_フタ検知	'C00506
LatchPH27_釜検知=LatchPH27_釜検知 or PH27_釜検知	'C00507
LatchPH28_フタ検知=LatchPH28_フタ検知 or PH28_フタ検知	'C00508
LatchPH29_釜検知=LatchPH29_釜検知 or PH29_釜検知	'C00509
LatchPH30_フタ検知=LatchPH30_フタ検知 or PH30_フタ検知	'C00510
LatchPH31_釜検知=LatchPH31_釜検知 or PH31_釜検知	'C00511
LatchXSW55_シリンダ上昇端A=LatchXSW55_シリンダ上昇端A or XSW55_シリンダ上昇端A	'C00529
LatchXSW56_シリンダ下降端A=LatchXSW56_シリンダ下降端A or XSW56_シリンダ下降端A	'C00530
LatchXSW57_シリンダ上昇端B=LatchXSW57_シリンダ上昇端B or XSW57_シリンダ上昇端B	'C00531
LatchXSW58_シリンダ下降端B=LatchXSW58_シリンダ下降端B or XSW58_シリンダ下降端B	'C00532
LatchXSW59_アンクランプ=LatchXSW59_アンクランプ or XSW59_アンクランプ	'C00533
LatchXSW60_クランプ=LatchXSW60_クランプ or XSW60_クランプ	'C00534
LatchXSW63_ストッパ下降端=LatchXSW63_ストッパ下降端 or XSW63_ストッパ下降端	'C00549
LatchXSW64_ストッパ上昇端=LatchXSW64_ストッパ上昇端 or XSW64_ストッパ上昇端	'C00550
LatchXSW65_ストッパ下降端=LatchXSW65_ストッパ下降端 or XSW65_ストッパ下降端	'C00551
LatchXSW66_ストッパ上昇端=LatchXSW66_ストッパ上昇端 or XSW66_ストッパ上昇端	'C00552
LatchPH32_釜検知=LatchPH32_釜検知 or PH32_釜検知	'C00553
LatchPH33_フタ検知=LatchPH33_フタ検知 or PH33_フタ検知	'C00554
LatchPH34_釜検知=LatchPH34_釜検知 or PH34_釜検知	'C00555
LatchPH35_フタ検知=LatchPH35_フタ検知 or PH35_フタ検知	'C00556
LatchXSW61_シリンダ上昇端=LatchXSW61_シリンダ上昇端 or XSW61_シリンダ上昇端	'C00562
LatchXSW62_シリンダ下降端=LatchXSW62_シリンダ下降端 or XSW62_シリンダ下降端	'C00563
LatchXSW67_リフト下降端=LatchXSW67_リフト下降端 or XSW67_リフト下降端	'C00597
LatchXSW68_リフト上昇端=LatchXSW68_リフト上昇端 or XSW68_リフト上昇端	'C00598
LatchXSW69_ストッパ下降端=LatchXSW69_ストッパ下降端 or XSW69_ストッパ下降端	'C00599
LatchXSW70_ストッパ上昇端=LatchXSW70_ストッパ上昇端 or XSW70_ストッパ上昇端	'C00600
LatchPH36_釜検知=LatchPH36_釜検知 or PH36_釜検知	'C00601
LatchPH37_フタ検知=LatchPH37_フタ検知 or PH37_フタ検知	'C00602
LatchPH48_釜検知=LatchPH48_釜検知 or PH48_釜検知	'C00603
LatchPH49_フタ検知=LatchPH49_フタ検知 or PH49_フタ検知	'C00604
LatchPH38_釜検知=LatchPH38_釜検知 or PH38_釜検知	'C00605
LatchPH43_釜検知=LatchPH43_釜検知 or PH43_釜検知	'C00627
LatchPH44_フタ検知=LatchPH44_フタ検知 or PH44_フタ検知	'C00628
LatchPH45_釜検知=LatchPH45_釜検知 or PH45_釜検知	'C00629
LatchPH46_フタ検知=LatchPH46_フタ検知 or PH46_フタ検知	'C00630
LatchLS7_釜反転機原点位置=LatchLS7_釜反転機原点位置 or LS7_釜反転機原点位置	'C00631
LatchLS8_釜反転機反転位置=LatchLS8_釜反転機反転位置 or LS8_釜反転機反転位置	'C00632
LatchXSW73_シリンダ上昇端=LatchXSW73_シリンダ上昇端 or XSW73_シリンダ上昇端	'C00641
LatchXSW80_シリンダ下降端=LatchXSW80_シリンダ下降端 or XSW80_シリンダ下降端	'C00642
LatchXSW83_釜フタ押さえ上昇端B=LatchXSW83_釜フタ押さえ上昇端B or XSW83_釜フタ押さえ上昇端B	'C00689
LatchXSW84_釜フタ押さえ下降端B=LatchXSW84_釜フタ押さえ下降端B or XSW84_釜フタ押さえ下降端B	'C00690
LatchXSW81_釜フタ押さえ上昇端A=LatchXSW81_釜フタ押さえ上昇端A or XSW81_釜フタ押さえ上昇端A	'C00691
LatchXSW82_釜フタ押さえ下降端A=LatchXSW82_釜フタ押さえ下降端A or XSW82_釜フタ押さえ下降端A	'C00692
LatchXSW85_釜フタストッパ下降端=LatchXSW85_釜フタストッパ下降端 or XSW85_釜フタストッパ下降端	'C00693
'LatchLS11_釜フタ検知=LatchLS11_釜フタ検知 or LS11_釜フタ検知	'C00694
LatchFLT1_タンク上限=LatchFLT1_タンク上限 or FLT1_タンク上限	'C00695
LatchFLT2_タンク下限=LatchFLT2_タンク下限 or FLT2_タンク下限	'C00696
LatchXSW88_釜フタ押さえ上昇端B=LatchXSW88_釜フタ押さえ上昇端B or XSW88_釜フタ押さえ上昇端B	'C00705
LatchXSW89_釜フタ押さえ下降端B=LatchXSW89_釜フタ押さえ下降端B or XSW89_釜フタ押さえ下降端B	'C00706
LatchXSW86_釜フタ押さえ上昇端A=LatchXSW86_釜フタ押さえ上昇端A or XSW86_釜フタ押さえ上昇端A	'C00707
LatchXSW87_釜フタ押さえ下降端A=LatchXSW87_釜フタ押さえ下降端A or XSW87_釜フタ押さえ下降端A	'C00708
LatchXSW90_釜フタストッパ下降端=LatchXSW90_釜フタストッパ下降端 or XSW90_釜フタストッパ下降端	'C00709
'LatchLS12_釜フタ検知=LatchLS12_釜フタ検知 or LS12_釜フタ検知	'C00710
LatchFLT3_タンク上限=LatchFLT3_タンク上限 or FLT3_タンク上限	'C00711
LatchFLT4_タンク下限=LatchFLT4_タンク下限 or FLT4_タンク下限	'C00712
LatchXSW93_釜フタ押さえ上昇端B=LatchXSW93_釜フタ押さえ上昇端B or XSW93_釜フタ押さえ上昇端B	'C00721
LatchXSW94_釜フタ押さえ下降端B=LatchXSW94_釜フタ押さえ下降端B or XSW94_釜フタ押さえ下降端B	'C00722
LatchXSW91_釜フタ押さえ上昇端A=LatchXSW91_釜フタ押さえ上昇端A or XSW91_釜フタ押さえ上昇端A	'C00723
LatchXSW92_釜フタ押さえ下降端A=LatchXSW92_釜フタ押さえ下降端A or XSW92_釜フタ押さえ下降端A	'C00724
LatchXSW95_釜フタストッパ下降端=LatchXSW95_釜フタストッパ下降端 or XSW95_釜フタストッパ下降端	'C00725
'LatchLS13_釜フタ検知=LatchLS13_釜フタ検知 or LS13_釜フタ検知	'C00726
LatchFLT5_タンク上限=LatchFLT5_タンク上限 or FLT5_タンク上限	'C00727
LatchFLT6_タンク下限=LatchFLT6_タンク下限 or FLT6_タンク下限	'C00728
LatchXSW98_釜フタ押さえ上昇端B=LatchXSW98_釜フタ押さえ上昇端B or XSW98_釜フタ押さえ上昇端B	'C00737
LatchXSW99_釜フタ押さえ下降端B=LatchXSW99_釜フタ押さえ下降端B or XSW99_釜フタ押さえ下降端B	'C00738
LatchXSW96_釜フタ押さえ上昇端A=LatchXSW96_釜フタ押さえ上昇端A or XSW96_釜フタ押さえ上昇端A	'C00739
LatchXSW97_釜フタ押さえ下降端A=LatchXSW97_釜フタ押さえ下降端A or XSW97_釜フタ押さえ下降端A	'C00740
LatchXSW100_釜フタストッパ下降端=LatchXSW100_釜フタストッパ下降端 or XSW100_釜フタストッパ下降端	'C00741
'LatchLS14_釜フタ検知=LatchLS14_釜フタ検知 or LS14_釜フタ検知	'C00742
LatchFLT7_タンク上限=LatchFLT7_タンク上限 or FLT7_タンク上限	'C00743
LatchFLT8_タンク下限=LatchFLT8_タンク下限 or FLT8_タンク下限	'C00744
LatchXSW103_釜フタ押さえ上昇端B=LatchXSW103_釜フタ押さえ上昇端B or XSW103_釜フタ押さえ上昇端B	'C00753
LatchXSW104_釜フタ押さえ下降端B=LatchXSW104_釜フタ押さえ下降端B or XSW104_釜フタ押さえ下降端B	'C00754
LatchXSW101_釜フタ押さえ上昇端A=LatchXSW101_釜フタ押さえ上昇端A or XSW101_釜フタ押さえ上昇端A	'C00755
LatchXSW102_釜フタ押さえ下降端A=LatchXSW102_釜フタ押さえ下降端A or XSW102_釜フタ押さえ下降端A	'C00756
LatchXSW105_釜フタストッパ下降端=LatchXSW105_釜フタストッパ下降端 or XSW105_釜フタストッパ下降端	'C00757
'LatchLS15_釜フタ検知=LatchLS15_釜フタ検知 or LS15_釜フタ検知	'C00758
LatchFLT9_タンク上限=LatchFLT9_タンク上限 or FLT9_タンク上限	'C00759
LatchFLT10_タンク下限=LatchFLT10_タンク下限 or FLT10_タンク下限	'C00760
'タイマー  （入力チャタリング）	'D00000
tmr(FLOS1_計量機近接センサー,timFLOS1_計量機近接センサー,#10)	'D00052
tmr(FLOS2_洗米無洗米切換検知,timFLOS2_洗米無洗米切換検知,#10)	'D00053
tmr(XSW9_送米切換A側,timXSW9_送米切換A側,#10)	'D00081
tmr(XSW10_送米切換B側,timXSW10_送米切換B側,#10)	'D00082
tmr(XSW1_充填バルブ開A,timXSW1_充填バルブ開A,#10)	'D00097
tmr(XSW2_充填バルブ閉A,timXSW2_充填バルブ閉A,#10)	'D00098
tmr(XSW3_水切りシャッター開A,timXSW3_水切りシャッター開A,#10)	'D00099
tmr(XSW4_水切りシャッター閉A,timXSW4_水切りシャッター閉A,#10)	'D00100
'tmr(PDL1_パドルセンサー上限A,timPDL1_パドルセンサー上限A,#10)	'D00106
tmr(PDL2_パドルセンサー下限A,timPDL2_パドルセンサー下限A,#10)	'D00107
tmr(XSW76_排水バルブ開A,timXSW76_排水バルブ開A,#10)	'D00108
tmr(XSW77_排水バルブ閉A,timXSW77_排水バルブ閉A,#10)	'D00109
tmr(FLOS3_LMT121,timFLOS3_LMT121,#10)	'D00111
tmr(XSW5_充填バルブ開B,timXSW5_充填バルブ開B,#10)	'D00129
tmr(XSW6_充填バルブ閉B,timXSW6_充填バルブ閉B,#10)	'D00130
tmr(XSW7_水切りシャッター開B,timXSW7_水切りシャッター開B,#10)	'D00131
tmr(XSW8_水切りシャッター閉B,timXSW8_水切りシャッター閉B,#10)	'D00132
'tmr(PDL3_パドルセンサー上限B,timPDL3_パドルセンサー上限B,#10)	'D00138
tmr(PDL4_パドルセンサー下限B,timPDL4_パドルセンサー下限B,#10)	'D00139
tmr(XSW78_排水バルブ開B,timXSW78_排水バルブ開B,#10)	'D00140
tmr(XSW79_排水バルブ閉B,timXSW79_排水バルブ閉B,#10)	'D00141
tmr(FLOS4_LMT121,timFLOS4_LMT121,#10)	'D00143
tmr(XSW106_計水バルブ開,timXSW106_計水バルブ開,#10)	'D00165
tmr(XSW107_計水バルブ閉,timXSW107_計水バルブ閉,#10)	'D00166
tmr(XSW11_ストッパ下降端,timXSW11_ストッパ下降端,#10)	'D00181
tmr(XSW12_ストッパ上昇端,timXSW12_ストッパ上昇端,#10)	'D00182
tmr(XSW13_ストッパ下降端,timXSW13_ストッパ下降端,#10)	'D00183
tmr(XSW14_ストッパ上昇端,timXSW14_ストッパ上昇端,#10)	'D00184
tmr(XSW15_リフト下降端,timXSW15_リフト下降端,#10)	'D00185
tmr(XSW16_リフト上昇端,timXSW16_リフト上昇端,#10)	'D00186
tmr(PH1_釜検知,timPH1_釜検知,#10)	'D00187
tmr(PH2_フタ検知,timPH2_フタ検知,#10)	'D00188
tmr(PH3_釜検知,timPH3_釜検知,#10)	'D00189
tmr(PH4_フタ検知,timPH4_フタ検知,#10)	'D00190
tmr(PH5_釜検知,timPH5_釜検知,#10)	'D00191
tmr(PH6_フタ検知,timPH6_フタ検知,#10)	'D00192
tmr(PH50_釜検知,timPH50_釜検知,#10)	'D00209
tmr(PH51_フタ検知,timPH51_フタ検知,#10)	'D00210
tmr(PH52_釜検知,timPH52_釜検知,#10)	'D00211
tmr(PH53_フタ検知,timPH53_フタ検知,#10)	'D00212
tmr(PH7_釜検知,timPH7_釜検知,#10)	'D00227
tmr(PH8_フタ検知,timPH8_フタ検知,#10)	'D00228
tmr(PH9_釜検知,timPH9_釜検知,#10)	'D00229
tmr(PH10_フタ検知,timPH10_フタ検知,#10)	'D00230
tmr(LS6_空釜反転反転位置,timLS6_空釜反転反転位置,#10)	'D00231
tmr(LS5_空釜反転原点位置,timLS5_空釜反転原点位置,#10)	'D00232
tmr(XSW17_リフト下降端,timXSW17_リフト下降端,#10)	'D00258
tmr(XSW18_リフト上昇端,timXSW18_リフト上昇端,#10)	'D00259
tmr(PH39_釜検知,timPH39_釜検知,#10)	'D00260
tmr(PH40_フタ検知,timPH40_フタ検知,#10)	'D00261
tmr(PH41_釜検知,timPH41_釜検知,#10)	'D00276
tmr(PH42_フタ検知,timPH42_フタ検知,#10)	'D00277
tmr(XSW19_ストッパ下降端,timXSW19_ストッパ下降端,#10)	'D00293
tmr(XSW20_ストッパ上昇端,timXSW20_ストッパ上昇端,#10)	'D00294
tmr(XSW21_ストッパ下降端,timXSW21_ストッパ下降端,#10)	'D00295
tmr(XSW22_ストッパ上昇端,timXSW22_ストッパ上昇端,#10)	'D00296
tmr(PH11_釜検知,timPH11_釜検知,#10)	'D00297
tmr(PH12_フタ検知,timPH12_フタ検知,#10)	'D00298
tmr(PH13_釜検知,timPH13_釜検知,#10)	'D00299
tmr(PH14_フタ検知,timPH14_フタ検知,#10)	'D00300
tmr(XSW23_ならし後退端,timXSW23_ならし後退端,#10)	'D00321
tmr(XSW24_ならし前進端,timXSW24_ならし前進端,#10)	'D00322
tmr(XSW25_ならし上昇端,timXSW25_ならし上昇端,#10)	'D00323
tmr(XSW26_ならし下降端,timXSW26_ならし下降端,#10)	'D00324
tmr(XSW27_ならし後退端,timXSW27_ならし後退端,#10)	'D00325
tmr(XSW28_ならし前進端,timXSW28_ならし前進端,#10)	'D00326
tmr(FL001_HH_Aタンク,timFL001_HH_Aタンク,#10)	'D00337
tmr(FL001_H_Aタンク,timFL001_H_Aタンク,#10)	'D00338
tmr(FL001_L_Aタンク,timFL001_L_Aタンク,#10)	'D00339
tmr(FL001_LL_Aタンク,timFL001_LL_Aタンク,#10)	'D00340
tmr(FL001_HH_Bタンク,timFL001_HH_Bタンク,#10)	'D00341
tmr(FL001_H_Bタンク,timFL001_H_Bタンク,#10)	'D00342
tmr(FL001_L_Bタンク,timFL001_L_Bタンク,#10)	'D00343
tmr(FL001_LL_Bタンク,timFL001_LL_Bタンク,#10)	'D00344
tmr(FL001_ALMC_Aタンク,timFL001_ALMC_Aタンク,#10)	'D00345
tmr(FL001_ALMC_Bタンク,timFL001_ALMC_Bタンク,#10)	'D00346
tmr(XSW29_ストッパ下降端,timXSW29_ストッパ下降端,#10)	'D00357
tmr(XSW30_ストッパ上昇端,timXSW30_ストッパ上昇端,#10)	'D00358
tmr(XSW31_ストッパ下降端,timXSW31_ストッパ下降端,#10)	'D00359
tmr(XSW32_ストッパ上昇端,timXSW32_ストッパ上昇端,#10)	'D00360
tmr(XSW33_クランプ下降端,timXSW33_クランプ下降端,#10)	'D00361
tmr(XSW34_クランプ上昇端,timXSW34_クランプ上昇端,#10)	'D00362
tmr(XSW35_クランプ下降端,timXSW35_クランプ下降端,#10)	'D00363
tmr(XSW36_クランプ上昇端,timXSW36_クランプ上昇端,#10)	'D00364
tmr(XSW37_リフト下降端,timXSW37_リフト下降端,#10)	'D00365
tmr(XSW38_リフト上昇端,timXSW38_リフト上昇端,#10)	'D00366
tmr(XSW74_ストッパ下降端,timXSW74_ストッパ下降端,#10)	'D00367
tmr(XSW75_ストッパ上昇端,timXSW75_ストッパ上昇端,#10)	'D00368
tmr(PH15_釜検知,timPH15_釜検知,#10)	'D00369
tmr(PH16_フタ検知,timPH16_フタ検知,#10)	'D00370
tmr(PH17_釜検知,timPH17_釜検知,#10)	'D00371
tmr(PH18_フタ検知,timPH18_フタ検知,#10)	'D00372
tmr(PH19_釜検知,timPH19_釜検知,#10)	'D00373
tmr(PH20_フタ検知,timPH20_フタ検知,#10)	'D00374
tmr(XSW39_シリンダ上昇端A,timXSW39_シリンダ上昇端A,#10)	'D00401
tmr(XSW40_シリンダ下降端A,timXSW40_シリンダ下降端A,#10)	'D00402
tmr(XSW41_シリンダ上昇端B,timXSW41_シリンダ上昇端B,#10)	'D00403
tmr(XSW42_シリンダ下降端B,timXSW42_シリンダ下降端B,#10)	'D00404
tmr(XSW43_クランプ,timXSW43_クランプ,#10)	'D00405
tmr(XSW44_アンクランプ,timXSW44_アンクランプ,#10)	'D00406
tmr(XSW111_釜位置右後退端,timXSW111_釜位置右後退端,#10)	'D00407
tmr(XSW112_釜位置左後退端,timXSW112_釜位置左後退端,#10)	'D00408
tmr(LS9_釜送り前進端,timLS9_釜送り前進端,#10)	'D00418
tmr(LS10_釜送り後退端,timLS10_釜送り後退端,#10)	'D00419
tmr(PH54_釜送りトリガ,timPH54_釜送りトリガ,#10)	'D00420
tmr(PH55_釜検知ステージ,timPH55_釜検知ステージ,#10)	'D00421
tmr(PH58_釜検知前ステージ,timPH58_釜検知前ステージ,#10)	'D00422
tmr(PH59_釜検知炊飯機入口,timPH59_釜検知炊飯機入口,#10)	'D00423
tmr(LS1_釜送り前進端,timLS1_釜送り前進端,#10)	'D00434
tmr(LS2_釜送り後退端,timLS2_釜送り後退端,#10)	'D00435
tmr(PH56_釜送りトリガ,timPH56_釜送りトリガ,#10)	'D00436
tmr(PH57_釜検知ステージ,timPH57_釜検知ステージ,#10)	'D00437
tmr(LS3_むらし機ピッチ検知,timLS3_むらし機ピッチ検知,#10)	'D00459
tmr(PH21_むらし機出口センサ,timPH21_むらし機出口センサ,#10)	'D00461
tmr(LS31_むらし機入口センサ,timLS31_むらし機入口センサ,#10)	'D00463
tmr(XSW45_ストッパ下降端,timXSW45_ストッパ下降端,#10)	'D00489
tmr(XSW46_ストッパ上昇端,timXSW46_ストッパ上昇端,#10)	'D00490
tmr(XSW47_リフト下降端,timXSW47_リフト下降端,#10)	'D00491
tmr(XSW48_リフト上昇端,timXSW48_リフト上昇端,#10)	'D00492
tmr(XSW49_ストッパ下降端,timXSW49_ストッパ下降端,#10)	'D00493
tmr(XSW50_ストッパ上昇端,timXSW50_ストッパ上昇端,#10)	'D00494
tmr(XSW51_ストッパ下降端,timXSW51_ストッパ下降端,#10)	'D00495
tmr(XSW52_ストッパ上昇端,timXSW52_ストッパ上昇端,#10)	'D00496
tmr(XSW53_リフト下降端,timXSW53_リフト下降端,#10)	'D00497
tmr(XSW54_リフト上昇端,timXSW54_リフト上昇端,#10)	'D00498
tmr(XSW71_バキューマリフト下降端,timXSW71_バキューマリフト下降端,#10)	'D00499
tmr(XSW72_バキューマリフト上昇端,timXSW72_バキューマリフト上昇端,#10)	'D00500
tmr(PH22_釜検知,timPH22_釜検知,#10)	'D00501
tmr(PH23_釜検知,timPH23_釜検知,#10)	'D00503
tmr(PH24_フタ検知,timPH24_フタ検知,#10)	'D00504
tmr(PH25_釜検知,timPH25_釜検知,#10)	'D00505
tmr(PH26_フタ検知,timPH26_フタ検知,#10)	'D00506
tmr(PH27_釜検知,timPH27_釜検知,#10)	'D00507
tmr(PH28_フタ検知,timPH28_フタ検知,#10)	'D00508
tmr(PH29_釜検知,timPH29_釜検知,#10)	'D00509
tmr(PH30_フタ検知,timPH30_フタ検知,#10)	'D00510
tmr(PH31_釜検知,timPH31_釜検知,#10)	'D00511
tmr(XSW55_シリンダ上昇端A,timXSW55_シリンダ上昇端A,#10)	'D00529
tmr(XSW56_シリンダ下降端A,timXSW56_シリンダ下降端A,#10)	'D00530
tmr(XSW57_シリンダ上昇端B,timXSW57_シリンダ上昇端B,#10)	'D00531
tmr(XSW58_シリンダ下降端B,timXSW58_シリンダ下降端B,#10)	'D00532
tmr(XSW59_アンクランプ,timXSW59_アンクランプ,#10)	'D00533
tmr(XSW60_クランプ,timXSW60_クランプ,#10)	'D00534
tmr(XSW63_ストッパ下降端,timXSW63_ストッパ下降端,#10)	'D00549
tmr(XSW64_ストッパ上昇端,timXSW64_ストッパ上昇端,#10)	'D00550
tmr(XSW65_ストッパ下降端,timXSW65_ストッパ下降端,#10)	'D00551
tmr(XSW66_ストッパ上昇端,timXSW66_ストッパ上昇端,#10)	'D00552
tmr(PH32_釜検知,timPH32_釜検知,#10)	'D00553
tmr(PH33_フタ検知,timPH33_フタ検知,#10)	'D00554
tmr(PH34_釜検知,timPH34_釜検知,#10)	'D00555
tmr(PH35_フタ検知,timPH35_フタ検知,#10)	'D00556
tmr(XSW61_シリンダ上昇端,timXSW61_シリンダ上昇端,#10)	'D00562
tmr(XSW62_シリンダ下降端,timXSW62_シリンダ下降端,#10)	'D00563
tmr(XSW67_リフト下降端,timXSW67_リフト下降端,#10)	'D00597
tmr(XSW68_リフト上昇端,timXSW68_リフト上昇端,#10)	'D00598
tmr(XSW69_ストッパ下降端,timXSW69_ストッパ下降端,#10)	'D00599
tmr(XSW70_ストッパ上昇端,timXSW70_ストッパ上昇端,#10)	'D00600
tmr(PH36_釜検知,timPH36_釜検知,#10)	'D00601
tmr(PH37_フタ検知,timPH37_フタ検知,#10)	'D00602
tmr(PH48_釜検知,timPH48_釜検知,#10)	'D00603
tmr(PH49_フタ検知,timPH49_フタ検知,#10)	'D00604
tmr(PH38_釜検知,timPH38_釜検知,#10)	'D00605
tmr(PH43_釜検知,timPH43_釜検知,#10)	'D00627
tmr(PH44_フタ検知,timPH44_フタ検知,#10)	'D00628
tmr(PH45_釜検知,timPH45_釜検知,#10)	'D00629
tmr(PH46_フタ検知,timPH46_フタ検知,#10)	'D00630
tmr(LS7_釜反転機原点位置,timLS7_釜反転機原点位置,#10)	'D00631
tmr(LS8_釜反転機反転位置,timLS8_釜反転機反転位置,#10)	'D00632
tmr(XSW73_シリンダ上昇端,timXSW73_シリンダ上昇端,#10)	'D00641
tmr(XSW80_シリンダ下降端,timXSW80_シリンダ下降端,#10)	'D00642
tmr(XSW83_釜フタ押さえ上昇端B,timXSW83_釜フタ押さえ上昇端B,#10)	'D00689
tmr(XSW84_釜フタ押さえ下降端B,timXSW84_釜フタ押さえ下降端B,#10)	'D00690
tmr(XSW81_釜フタ押さえ上昇端A,timXSW81_釜フタ押さえ上昇端A,#10)	'D00691
tmr(XSW82_釜フタ押さえ下降端A,timXSW82_釜フタ押さえ下降端A,#10)	'D00692
tmr(XSW85_釜フタストッパ下降端,timXSW85_釜フタストッパ下降端,#10)	'D00693
'tmr(LS11_釜フタ検知,timLS11_釜フタ検知,#10)	'D00694
tmr(FLT1_タンク上限,timFLT1_タンク上限,#10)	'D00695
tmr(FLT2_タンク下限,timFLT2_タンク下限,#1800)	'D00696
tmr(XSW88_釜フタ押さえ上昇端B,timXSW88_釜フタ押さえ上昇端B,#10)	'D00705
tmr(XSW89_釜フタ押さえ下降端B,timXSW89_釜フタ押さえ下降端B,#10)	'D00706
tmr(XSW86_釜フタ押さえ上昇端A,timXSW86_釜フタ押さえ上昇端A,#10)	'D00707
tmr(XSW87_釜フタ押さえ下降端A,timXSW87_釜フタ押さえ下降端A,#10)	'D00708
tmr(XSW90_釜フタストッパ下降端,timXSW90_釜フタストッパ下降端,#10)	'D00709
'tmr(LS12_釜フタ検知,timLS12_釜フタ検知,#10)	'D00710
tmr(FLT3_タンク上限,timFLT3_タンク上限,#10)	'D00711
tmr(FLT4_タンク下限,timFLT4_タンク下限,#1800)	'D00712
tmr(XSW93_釜フタ押さえ上昇端B,timXSW93_釜フタ押さえ上昇端B,#10)	'D00721
tmr(XSW94_釜フタ押さえ下降端B,timXSW94_釜フタ押さえ下降端B,#10)	'D00722
tmr(XSW91_釜フタ押さえ上昇端A,timXSW91_釜フタ押さえ上昇端A,#10)	'D00723
tmr(XSW92_釜フタ押さえ下降端A,timXSW92_釜フタ押さえ下降端A,#10)	'D00724
tmr(XSW95_釜フタストッパ下降端,timXSW95_釜フタストッパ下降端,#10)	'D00725
'tmr(LS13_釜フタ検知,timLS13_釜フタ検知,#10)	'D00726
tmr(FLT5_タンク上限,timFLT5_タンク上限,#10)	'D00727
tmr(FLT6_タンク下限,timFLT6_タンク下限,#1800)	'D00728
tmr(XSW98_釜フタ押さえ上昇端B,timXSW98_釜フタ押さえ上昇端B,#10)	'D00737
tmr(XSW99_釜フタ押さえ下降端B,timXSW99_釜フタ押さえ下降端B,#10)	'D00738
tmr(XSW96_釜フタ押さえ上昇端A,timXSW96_釜フタ押さえ上昇端A,#10)	'D00739
tmr(XSW97_釜フタ押さえ下降端A,timXSW97_釜フタ押さえ下降端A,#10)	'D00740
tmr(XSW100_釜フタストッパ下降端,timXSW100_釜フタストッパ下降端,#10)	'D00741
'tmr(LS14_釜フタ検知,timLS14_釜フタ検知,#10)	'D00742
tmr(FLT7_タンク上限,timFLT7_タンク上限,#10)	'D00743
tmr(FLT8_タンク下限,timFLT8_タンク下限,#1800)	'D00744
tmr(XSW103_釜フタ押さえ上昇端B,timXSW103_釜フタ押さえ上昇端B,#10)	'D00753
tmr(XSW104_釜フタ押さえ下降端B,timXSW104_釜フタ押さえ下降端B,#10)	'D00754
tmr(XSW101_釜フタ押さえ上昇端A,timXSW101_釜フタ押さえ上昇端A,#10)	'D00755
tmr(XSW102_釜フタ押さえ下降端A,timXSW102_釜フタ押さえ下降端A,#10)	'D00756
tmr(XSW105_釜フタストッパ下降端,timXSW105_釜フタストッパ下降端,#10)	'D00757
'tmr(LS15_釜フタ検知,timLS15_釜フタ検知,#10)	'D00758
tmr(FLT9_タンク上限,timFLT9_タンク上限,#10)	'D00759
tmr(FLT10_タンク下限,timFLT10_タンク下限,#1800)	'D00760
'タイマー  passxxx (センサーレスタイマー）	'E00000
'カウンター  出力デバイスライフカウンター	'F00000
cnt(CNT_MC4_送米ポンプ,1000000,MC4_送米ポンプ)	'F00009
cnt(CNT_MC5_洗米羽根,1000000,MC5_洗米羽根)	'F00010
cnt(CNT_SV1_給水電磁弁,1000000,SV1_給水電磁弁)	'F00011
cnt(CNT_SV58_洗米バルブA,1000000,SV58_洗米バルブA)	'F00012
cnt(CNT_MC1_張込用昇降機,1000000,MC1_張込用昇降機)	'F00065
cnt(CNT_MC2_排出用昇降機,1000000,MC2_排出用昇降機)	'F00066
cnt(CNT_MC3_計量機,1000000,MC3_計量機)	'F00067
cnt(CNT_SV12_送米切換バルブA側,1000000,SV12_送米切換バルブA側)	'F00091
cnt(CNT_SV13_送米切換バルブB側,1000000,SV13_送米切換バルブB側)	'F00092
cnt(CNT_SV2_充填バルブ開A,1000000,SV2_充填バルブ開A)	'F00113
cnt(CNT_SV4_水切りシャッター開A,1000000,SV4_水切りシャッター開A)	'F00115
cnt(CNT_SV5_水切りシャッター閉A,1000000,SV5_水切りシャッター閉A)	'F00116
cnt(CNT_SV6_給水電磁弁A,1000000,SV6_給水電磁弁A)	'F00117
cnt(CNT_SV60_排水バルブ開A,1000000,SV60_排水バルブ開A)	'F00122
cnt(CNT_SV7_充填バルブ開B,1000000,SV7_充填バルブ開B)	'F00145
cnt(CNT_SV9_水切りシャッター開B,1000000,SV9_水切りシャッター開B)	'F00147
cnt(CNT_SV10_水切りシャッター閉B,1000000,SV10_水切りシャッター閉B)	'F00148
cnt(CNT_SV11_給水電磁弁B,1000000,SV11_給水電磁弁B)	'F00149
cnt(CNT_SV62_排水バルブ開B,1000000,SV62_排水バルブ開B)	'F00154
cnt(CNT_SV17_計水タンク給水（大）,1000000,SV17_計水タンク給水（大）)	'F00169
cnt(CNT_SV18_計水タンク給水（小）,1000000,SV18_計水タンク給水（小）)	'F00170
cnt(CNT_SV19_計水電磁弁_A,1000000,SV19_計水電磁弁_A)	'F00171
cnt(CNT_MC6_搬送モータ,1000000,MC6_搬送モータ)	'F00193
cnt(CNT_MC7_搬送モータ,1000000,MC7_搬送モータ)	'F00194
cnt(CNT_MC8_搬送モータ,1000000,MC8_搬送モータ)	'F00195
cnt(CNT_MC9_モータローラ,1000000,MC9_モータローラ)	'F00196
cnt(CNT_SV14_ストッパ,1000000,SV14_ストッパ)	'F00197
cnt(CNT_SV15_ストッパ,1000000,SV15_ストッパ)	'F00198
cnt(CNT_SV16_リフト,1000000,SV16_リフト)	'F00199
cnt(CNT_MC10_反転モータ正転,1000000,MC10_反転モータ正転)	'F00233
cnt(CNT_MC10_反転モータ逆転,1000000,MC10_反転モータ逆転)	'F00234
cnt(CNT_MC32_搬送モータ,1000000,MC32_搬送モータ)	'F00235
cnt(CNT_MC11_搬送モータ,1000000,MC11_搬送モータ)	'F00265
cnt(CNT_SV20_リフト上昇,1000000,SV20_リフト上昇)	'F00266
cnt(CNT_SV100_リフト下降,1000000,SV100_リフト下降)	'F00267
cnt(CNT_MC30_搬送モータ,1000000,MC30_搬送モータ)	'F00281
cnt(CNT_MC12_搬送モータ,1000000,MC12_搬送モータ)	'F00305
cnt(CNT_MC13_搬送モータ,1000000,MC13_搬送モータ)	'F00306
cnt(CNT_SV21_ストッパ,1000000,SV21_ストッパ)	'F00309
cnt(CNT_SV22_ストッパ,1000000,SV22_ストッパ)	'F00310
cnt(CNT_SV23_ならし前進,1000000,SV23_ならし前進)	'F00329
cnt(CNT_SV24_ならし後退,1000000,SV24_ならし後退)	'F00330
cnt(CNT_SV25_ならし下降,1000000,SV25_ならし下降)	'F00331
cnt(CNT_SV26_ならし上昇,1000000,SV26_ならし上昇)	'F00332
cnt(CNT_SV27_ならし前進,1000000,SV27_ならし前進)	'F00333
cnt(CNT_SV28_ならし後退,1000000,SV28_ならし後退)	'F00334
cnt(CNT_MC14_搬送モータ,1000000,MC14_搬送モータ)	'F00385
cnt(CNT_MC15_搬送モータ,1000000,MC15_搬送モータ)	'F00386
cnt(CNT_MC16_モータローラ,1000000,MC16_モータローラ)	'F00387
cnt(CNT_SV29_ストッパ,1000000,SV29_ストッパ)	'F00393
cnt(CNT_SV30_ストッパ,1000000,SV30_ストッパ)	'F00394
cnt(CNT_SV31_クランプ,1000000,SV31_クランプ)	'F00395
cnt(CNT_SV32_クランプ,1000000,SV32_クランプ)	'F00396
cnt(CNT_SV33_リフト,1000000,SV33_リフト)	'F00397
cnt(CNT_SV65_ストッパ,1000000,SV65_ストッパ)	'F00398
cnt(CNT_SV34_シリンダ上昇A,1000000,SV34_シリンダ上昇A)	'F00409
cnt(CNT_SV35_シリンダ下降A,1000000,SV35_シリンダ下降A)	'F00410
cnt(CNT_SV36_シリンダ上昇B,1000000,SV36_シリンダ上昇B)	'F00411
cnt(CNT_SV37_シリンダ下降B,1000000,SV37_シリンダ下降B)	'F00412
cnt(CNT_SV38_クランプ,1000000,SV38_クランプ)	'F00413
cnt(CNT_SV39_アンクランプ,1000000,SV39_アンクランプ)	'F00414
cnt(CNT_SV64_釜位置,1000000,SV64_釜位置)	'F00415
cnt(CNT_MC34_釜送り正転,1000000,MC34_釜送り正転)	'F00425
cnt(CNT_MC34_釜送り逆転,1000000,MC34_釜送り逆転)	'F00426
cnt(CNT_MC43_乗移コンベア,1000000,MC43_乗移コンベア)	'F00427
cnt(CNT_MC18_釜送り逆転,1000000,MC18_釜送り逆転)	'F00441
cnt(CNT_MC18_釜送り正転,1000000,MC18_釜送り正転)	'F00442
cnt(CNT_MC17_むらし機モータ,1000000,MC17_むらし機モータ)	'F00465
cnt(CNT_MC19_搬送モータ,1000000,MC19_搬送モータ)	'F00513
cnt(CNT_MC20_搬送モータ,1000000,MC20_搬送モータ)	'F00514
cnt(CNT_MC21_搬送モータ正転,1000000,MC21_搬送モータ正転)	'F00515
cnt(CNT_MC21_搬送モータ逆転,1000000,MC21_搬送モータ逆転)	'F00516
cnt(CNT_MC22_搬送モータ正転,1000000,MC22_搬送モータ正転)	'F00517
cnt(CNT_MC22_搬送モータ逆転,1000000,MC22_搬送モータ逆転)	'F00518
cnt(CNT_MC23_モータローラ,1000000,MC23_モータローラ)	'F00519
cnt(CNT_SV40_ストッパ,1000000,SV40_ストッパ)	'F00521
cnt(CNT_SV41_リフト,1000000,SV41_リフト)	'F00522
cnt(CNT_SV42_ストッパ,1000000,SV42_ストッパ)	'F00523
cnt(CNT_SV43_ストッパ,1000000,SV43_ストッパ)	'F00524
cnt(CNT_SV44_リフト,1000000,SV44_リフト)	'F00525
cnt(CNT_SV57_バキュームリフト,1000000,SV57_バキュームリフト)	'F00526
cnt(CNT_SV45_シリンダ上昇A,1000000,SV45_シリンダ上昇A)	'F00537
cnt(CNT_SV46_シリンダ下降A,1000000,SV46_シリンダ下降A)	'F00538
cnt(CNT_SV47_シリンダ上昇B,1000000,SV47_シリンダ上昇B)	'F00539
cnt(CNT_SV48_シリンダ下降B,1000000,SV48_シリンダ下降B)	'F00540
cnt(CNT_SV49_アンクランプ,1000000,SV49_アンクランプ)	'F00541
cnt(CNT_SV50_クランプ,1000000,SV50_クランプ)	'F00542
cnt(CNT_MC24_吸引ポンプ,1000000,MC24_吸引ポンプ)	'F00569
cnt(CNT_SV51_給水電磁弁,1000000,SV51_給水電磁弁)	'F00570
cnt(CNT_SV52_シリンダ,1000000,SV52_シリンダ)	'F00571
cnt(CNT_MC25_搬送モータ,1000000,MC25_搬送モータ)	'F00577
cnt(CNT_MC26_搬送モータ,1000000,MC26_搬送モータ)	'F00578
cnt(CNT_SV53_ストッパ,1000000,SV53_ストッパ)	'F00579
cnt(CNT_SV54_ストッパ,1000000,SV54_ストッパ)	'F00580
cnt(CNT_MC28_搬送モータ正転,1000000,MC28_搬送モータ正転)	'F00609
cnt(CNT_MC28_搬送モータ逆転,1000000,MC28_搬送モータ逆転)	'F00610
cnt(CNT_MC29_搬送モータ正転,1000000,MC29_搬送モータ正転)	'F00611
cnt(CNT_MC29_搬送モータ逆転,1000000,MC29_搬送モータ逆転)	'F00612
cnt(CNT_MC27_モータローラ,1000000,MC27_モータローラ)	'F00613
cnt(CNT_SV55_リフト,1000000,SV55_リフト)	'F00617
cnt(CNT_SV56_ストッパ,1000000,SV56_ストッパ)	'F00618
cnt(CNT_MC31_反転モータ正転,1000000,MC31_反転モータ正転)	'F00633
cnt(CNT_MC31_反転モータ逆転,1000000,MC31_反転モータ逆転)	'F00634
cnt(CNT_MC33_搬送モータ,1000000,MC33_搬送モータ)	'F00635
cnt(CNT_SV58_シリンダ,1000000,SV58_シリンダ)	'F00649
cnt(CNT_MC35_洗浄ポンプA,1000000,MC35_洗浄ポンプA)	'F00681
cnt(CNT_MC36_洗浄ポンプB,1000000,MC36_洗浄ポンプB)	'F00682
cnt(CNT_MC37_洗浄ポンプC,1000000,MC37_洗浄ポンプC)	'F00683
cnt(CNT_MC38_洗浄ポンプD,1000000,MC38_洗浄ポンプD)	'F00684
cnt(CNT_MC39_洗浄ポンプE,1000000,MC39_洗浄ポンプE)	'F00685
cnt(CNT_MC1_インバータ用電源,1000000,MC1_インバータ用電源)	'F00686
cnt(CNT_SV67_釜フタ押さえ下降A,1000000,SV67_釜フタ押さえ下降A)	'F00697
cnt(CNT_SV68_釜フタ押さえ下降B,1000000,SV68_釜フタ押さえ下降B)	'F00698
cnt(CNT_SV69_給湯電磁弁,1000000,SV69_給湯電磁弁)	'F00699
cnt(CNT_SV70_蒸気電磁弁,1000000,SV70_蒸気電磁弁)	'F00700
cnt(CNT_SV71_釜フタストッパ,1000000,SV71_釜フタストッパ)	'F00701
cnt(CNT_SV72_下洗浄電磁弁,1000000,SV72_下洗浄電磁弁)	'F00702
cnt(CNT_SV73_釜フタ押さえ下降A,1000000,SV73_釜フタ押さえ下降A)	'F00713
cnt(CNT_SV74_釜フタ押さえ下降B,1000000,SV74_釜フタ押さえ下降B)	'F00714
cnt(CNT_SV75_給湯電磁弁,1000000,SV75_給湯電磁弁)	'F00715
cnt(CNT_SV76_蒸気電磁弁,1000000,SV76_蒸気電磁弁)	'F00716
cnt(CNT_SV77_釜フタストッパ,1000000,SV77_釜フタストッパ)	'F00717
cnt(CNT_SV78_下洗浄電磁弁,1000000,SV78_下洗浄電磁弁)	'F00718
cnt(CNT_SV79_釜フタ押さえ下降A,1000000,SV79_釜フタ押さえ下降A)	'F00729
cnt(CNT_SV80_釜フタ押さえ下降B,1000000,SV80_釜フタ押さえ下降B)	'F00730
cnt(CNT_SV81_給湯電磁弁,1000000,SV81_給湯電磁弁)	'F00731
cnt(CNT_SV82_蒸気電磁弁,1000000,SV82_蒸気電磁弁)	'F00732
cnt(CNT_SV83_釜フタストッパ,1000000,SV83_釜フタストッパ)	'F00733
cnt(CNT_SV84_下洗浄電磁弁,1000000,SV84_下洗浄電磁弁)	'F00734
cnt(CNT_SV85_釜フタ押さえ下降A,1000000,SV85_釜フタ押さえ下降A)	'F00745
cnt(CNT_SV86_釜フタ押さえ下降B,1000000,SV86_釜フタ押さえ下降B)	'F00746
cnt(CNT_SV87_給湯電磁弁,1000000,SV87_給湯電磁弁)	'F00747
cnt(CNT_SV88_蒸気電磁弁,1000000,SV88_蒸気電磁弁)	'F00748
cnt(CNT_SV89_釜フタストッパ,1000000,SV89_釜フタストッパ)	'F00749
cnt(CNT_SV90_下洗浄電磁弁,1000000,SV90_下洗浄電磁弁)	'F00750
cnt(CNT_SV91_釜フタ押さえ下降A,1000000,SV91_釜フタ押さえ下降A)	'F00761
cnt(CNT_SV92_釜フタ押さえ下降B,1000000,SV92_釜フタ押さえ下降B)	'F00762
cnt(CNT_SV93_給湯電磁弁,1000000,SV93_給湯電磁弁)	'F00763
cnt(CNT_SV94_蒸気電磁弁,1000000,SV94_蒸気電磁弁)	'F00764
cnt(CNT_SV95_釜フタストッパ,1000000,SV95_釜フタストッパ)	'F00765
cnt(CNT_SV96_下洗浄電磁弁,1000000,SV96_下洗浄電磁弁)	'F00766
cnt(CNT_SV97_すすぎ電磁弁,1000000,SV97_すすぎ電磁弁)	'F00785
cnt(CNT_SV98_仕上げ電磁弁,1000000,SV98_仕上げ電磁弁)	'F00786
cnt(CNT_INV1_コンベアモータ正転,1000000,INV1_コンベアモータ正転)	'F00801
cnt(CNT_INV1_コンベア異常,1000000,INV1_コンベア異常)	'F00802
cnt(CNT_INV2_コンベアモータ正転,1000000,INV2_コンベアモータ正転)	'F00805
cnt(CNT_INV2_コンベア異常,1000000,INV2_コンベア異常)	'F00806
cnt(CNT_INV3_コンベアモータ正転,1000000,INV3_コンベアモータ正転)	'F00809
cnt(CNT_INV3_コンベア異常,1000000,INV3_コンベア異常)	'F00810
cnt(CNT_INV4_コンベア異常,1000000,INV4_コンベア異常)	'F00849
cnt(CNT_INV4_コンベア電源確認,1000000,INV4_コンベア電源確認)	'F00850
cnt(CNT_INV4_コンベア動作中,1000000,INV4_コンベア動作中)	'F00851
cnt(CNT_INV4_インバータ正転,1000000,INV4_インバータ正転)	'F00857
cnt(CNT_INV4_インバータ停止,1000000,INV4_インバータ停止)	'F00858
'出力デバイス  ライフカウンタークリア	'G00000

if ldp(clrPBMC4_送米ポンプ) then
    res(CNT_MC4_送米ポンプ)
end if
	'G00009

if ldp(clrPBMC5_洗米羽根) then
    res(CNT_MC5_洗米羽根)
end if
	'G00010

if ldp(clrPBSV1_給水電磁弁) then
    res(CNT_SV1_給水電磁弁)
end if
	'G00011

if ldp(clrPBSV58_洗米バルブA) then
    res(CNT_SV58_洗米バルブA)
end if
	'G00012
if ldp(clrPBMC1_張込用昇降機) then
    res(CNT_MC1_張込用昇降機)
end if	'G00065
if ldp(clrPBMC2_排出用昇降機) then
    res(CNT_MC2_排出用昇降機)
end if	'G00066
if ldp(clrPBMC3_計量機) then
    res(CNT_MC3_計量機)
end if	'G00067
'if ldp(clrPBSV12_送米切換バルブA側) then
'    res(CNT_SV12_送米切換バルブA側)
'end if	'G00091
'if ldp(clrPBSV13_送米切換バルブB側) then
'    res(CNT_SV13_送米切換バルブB側)
'end if	'G00092
if ldp(clrPBSV2_充填バルブ開A) then
    res(CNT_SV2_充填バルブ開A)
end if	'G00113
'if ldp(clrPBSV4_水切りシャッター開A) then
'    res(CNT_SV4_水切りシャッター開A)
'end if	'G00115
'if ldp(clrPBSV5_水切りシャッター閉A) then
'    res(CNT_SV5_水切りシャッター閉A)
'end if	'G00116
if ldp(clrPBSV6_給水電磁弁A) then
    res(CNT_SV6_給水電磁弁A)
end if	'G00117
if ldp(clrPBSV60_排水バルブ開A) then
    res(CNT_SV60_排水バルブ開A)
end if	'G00122
if ldp(clrPBSV7_充填バルブ開B) then
    res(CNT_SV7_充填バルブ開B)
end if	'G00145
'if ldp(clrPBSV9_水切りシャッター開B) then
'    res(CNT_SV9_水切りシャッター開B)
'end if	'G00147
'if ldp(clrPBSV10_水切りシャッター閉B) then
'    res(CNT_SV10_水切りシャッター閉B)
'end if	'G00148
if ldp(clrPBSV11_給水電磁弁B) then
    res(CNT_SV11_給水電磁弁B)
end if	'G00149
if ldp(clrPBSV62_排水バルブ開B) then
    res(CNT_SV62_排水バルブ開B)
end if	'G00154
if ldp(clrPBSV17_計水タンク給水（大）) then
    res(CNT_SV17_計水タンク給水（大）)
end if	'G00169
if ldp(clrPBSV18_計水タンク給水（小）) then
    res(CNT_SV18_計水タンク給水（小）)
end if	'G00170
if ldp(clrPBSV19_計水電磁弁_A) then
    res(CNT_SV19_計水電磁弁_A)
end if	'G00171
if ldp(clrPBMC6_搬送モータ) then
    res(CNT_MC6_搬送モータ)
end if	'G00193
if ldp(clrPBMC7_搬送モータ) then
    res(CNT_MC7_搬送モータ)
end if	'G00194
if ldp(clrPBMC8_搬送モータ) then
    res(CNT_MC8_搬送モータ)
end if	'G00195
if ldp(clrPBMC9_モータローラ) then
    res(CNT_MC9_モータローラ)
end if	'G00196
if ldp(clrPBSV14_ストッパ) then
    res(CNT_SV14_ストッパ)
end if	'G00197
if ldp(clrPBSV15_ストッパ) then
    res(CNT_SV15_ストッパ)
end if	'G00198
if ldp(clrPBSV16_リフト) then
    res(CNT_SV16_リフト)
end if	'G00199
if ldp(clrPBMC10_反転モータ正転) then
    res(CNT_MC10_反転モータ正転)
end if	'G00233
if ldp(clrPBMC10_反転モータ逆転) then
    res(CNT_MC10_反転モータ逆転)
end if	'G00234
if ldp(clrPBMC32_搬送モータ) then
    res(CNT_MC32_搬送モータ)
end if	'G00235
if ldp(clrPBMC11_搬送モータ) then
    res(CNT_MC11_搬送モータ)
end if	'G00265
'if ldp(clrPBSV20_リフト上昇) then
'    res(CNT_SV20_リフト上昇)
'end if	'G00266
'if ldp(clrPBSV100_リフト下降) then
'    res(CNT_SV100_リフト下降)
'end if	'G00267
if ldp(clrPBMC30_搬送モータ) then
    res(CNT_MC30_搬送モータ)
end if	'G00281
if ldp(clrPBMC12_搬送モータ) then
    res(CNT_MC12_搬送モータ)
end if	'G00305
if ldp(clrPBMC13_搬送モータ) then
    res(CNT_MC13_搬送モータ)
end if	'G00306
if ldp(clrPBSV21_ストッパ) then
    res(CNT_SV21_ストッパ)
end if	'G00309
if ldp(clrPBSV22_ストッパ) then
    res(CNT_SV22_ストッパ)
end if	'G00310
'if ldp(clrPBSV23_ならし前進) then
'    res(CNT_SV23_ならし前進)
'end if	'G00329
'if ldp(clrPBSV24_ならし後退) then
'    res(CNT_SV24_ならし後退)
'end if	'G00330
'if ldp(clrPBSV25_ならし下降) then
'    res(CNT_SV25_ならし下降)
'end if	'G00331
'if ldp(clrPBSV26_ならし上昇) then
'    res(CNT_SV26_ならし上昇)
'end if	'G00332
'if ldp(clrPBSV27_ならし前進) then
'    res(CNT_SV27_ならし前進)
'end if	'G00333
'if ldp(clrPBSV28_ならし後退) then
'    res(CNT_SV28_ならし後退)
'end if	'G00334
if ldp(clrPBMC14_搬送モータ) then
    res(CNT_MC14_搬送モータ)
end if	'G00385
if ldp(clrPBMC15_搬送モータ) then
    res(CNT_MC15_搬送モータ)
end if	'G00386
if ldp(clrPBMC16_モータローラ) then
    res(CNT_MC16_モータローラ)
end if	'G00387
if ldp(clrPBSV29_ストッパ) then
    res(CNT_SV29_ストッパ)
end if	'G00393
if ldp(clrPBSV30_ストッパ) then
    res(CNT_SV30_ストッパ)
end if	'G00394
if ldp(clrPBSV31_クランプ) then
    res(CNT_SV31_クランプ)
end if	'G00395
if ldp(clrPBSV32_クランプ) then
    res(CNT_SV32_クランプ)
end if	'G00396
if ldp(clrPBSV33_リフト) then
    res(CNT_SV33_リフト)
end if	'G00397
if ldp(clrPBSV65_ストッパ) then
    res(CNT_SV65_ストッパ)
end if	'G00398
'if ldp(clrPBSV34_シリンダ上昇A) then
'    res(CNT_SV34_シリンダ上昇A)
'end if	'G00409
'if ldp(clrPBSV35_シリンダ下降A) then
'    res(CNT_SV35_シリンダ下降A)
'end if	'G00410
'if ldp(clrPBSV36_シリンダ上昇B) then
'    res(CNT_SV36_シリンダ上昇B)
'end if	'G00411
'if ldp(clrPBSV37_シリンダ下降B) then
'    res(CNT_SV37_シリンダ下降B)
'end if	'G00412
'if ldp(clrPBSV38_クランプ) then
'    res(CNT_SV38_クランプ)
'end if	'G00413
'if ldp(clrPBSV39_アンクランプ) then
'    res(CNT_SV39_アンクランプ)
'end if	'G00414
if ldp(clrPBSV64_釜位置) then
    res(CNT_SV64_釜位置)
end if	'G00415
if ldp(clrPBMC34_釜送り正転) then
    res(CNT_MC34_釜送り正転)
end if	'G00425
if ldp(clrPBMC34_釜送り逆転) then
    res(CNT_MC34_釜送り逆転)
end if	'G00426
if ldp(clrPBMC43_乗移コンベア) then
    res(CNT_MC43_乗移コンベア)
end if	'G00427
if ldp(clrPBMC18_釜送り逆転) then
    res(CNT_MC18_釜送り逆転)
end if	'G00441
if ldp(clrPBMC18_釜送り正転) then
    res(CNT_MC18_釜送り正転)
end if	'G00442
if ldp(clrPBMC17_むらし機モータ) then
    res(CNT_MC17_むらし機モータ)
end if	'G00465
if ldp(clrPBMC19_搬送モータ) then
    res(CNT_MC19_搬送モータ)
end if	'G00513
if ldp(clrPBMC20_搬送モータ) then
    res(CNT_MC20_搬送モータ)
end if	'G00514
if ldp(clrPBMC21_搬送モータ正転) then
    res(CNT_MC21_搬送モータ正転)
end if	'G00515
if ldp(clrPBMC21_搬送モータ逆転) then
    res(CNT_MC21_搬送モータ逆転)
end if	'G00516
if ldp(clrPBMC22_搬送モータ正転) then
    res(CNT_MC22_搬送モータ正転)
end if	'G00517
if ldp(clrPBMC22_搬送モータ逆転) then
    res(CNT_MC22_搬送モータ逆転)
end if	'G00518
if ldp(clrPBMC23_モータローラ) then
    res(CNT_MC23_モータローラ)
end if	'G00519
if ldp(clrPBSV40_ストッパ) then
    res(CNT_SV40_ストッパ)
end if	'G00521
if ldp(clrPBSV41_リフト) then
    res(CNT_SV41_リフト)
end if	'G00522
if ldp(clrPBSV42_ストッパ) then
    res(CNT_SV42_ストッパ)
end if	'G00523
if ldp(clrPBSV43_ストッパ) then
    res(CNT_SV43_ストッパ)
end if	'G00524
if ldp(clrPBSV44_リフト) then
    res(CNT_SV44_リフト)
end if	'G00525
if ldp(clrPBSV57_バキュームリフト) then
    res(CNT_SV57_バキュームリフト)
end if	'G00526
'if ldp(clrPBSV45_シリンダ上昇A) then
'    res(CNT_SV45_シリンダ上昇A)
'end if	'G00537
'if ldp(clrPBSV46_シリンダ下降A) then
'    res(CNT_SV46_シリンダ下降A)
'end if	'G00538
'if ldp(clrPBSV47_シリンダ上昇B) then
'    res(CNT_SV47_シリンダ上昇B)
'end if	'G00539
'if ldp(clrPBSV48_シリンダ下降B) then
'    res(CNT_SV48_シリンダ下降B)
'end if	'G00540
'if ldp(clrPBSV49_アンクランプ) then
'    res(CNT_SV49_アンクランプ)
'end if	'G00541
'if ldp(clrPBSV50_クランプ) then
'    res(CNT_SV50_クランプ)
'end if	'G00542
if ldp(clrPBMC24_吸引ポンプ) then
    res(CNT_MC24_吸引ポンプ)
end if	'G00569
if ldp(clrPBSV51_給水電磁弁) then
    res(CNT_SV51_給水電磁弁)
end if	'G00570
if ldp(clrPBSV52_シリンダ) then
    res(CNT_SV52_シリンダ)
end if	'G00571
if ldp(clrPBMC25_搬送モータ) then
    res(CNT_MC25_搬送モータ)
end if	'G00577
if ldp(clrPBMC26_搬送モータ) then
    res(CNT_MC26_搬送モータ)
end if	'G00578
if ldp(clrPBSV53_ストッパ) then
    res(CNT_SV53_ストッパ)
end if	'G00579
if ldp(clrPBSV54_ストッパ) then
    res(CNT_SV54_ストッパ)
end if	'G00580
if ldp(clrPBMC28_搬送モータ正転) then
    res(CNT_MC28_搬送モータ正転)
end if	'G00609
if ldp(clrPBMC28_搬送モータ逆転) then
    res(CNT_MC28_搬送モータ逆転)
end if	'G00610
if ldp(clrPBMC29_搬送モータ正転) then
    res(CNT_MC29_搬送モータ正転)
end if	'G00611
if ldp(clrPBMC29_搬送モータ逆転) then
    res(CNT_MC29_搬送モータ逆転)
end if	'G00612
if ldp(clrPBMC27_モータローラ) then
    res(CNT_MC27_モータローラ)
end if	'G00613
if ldp(clrPBSV55_リフト) then
    res(CNT_SV55_リフト)
end if	'G00617
if ldp(clrPBSV56_ストッパ) then
    res(CNT_SV56_ストッパ)
end if	'G00618
if ldp(clrPBMC31_反転モータ正転) then
    res(CNT_MC31_反転モータ正転)
end if	'G00633
if ldp(clrPBMC31_反転モータ逆転) then
    res(CNT_MC31_反転モータ逆転)
end if	'G00634
if ldp(clrPBMC33_搬送モータ) then
    res(CNT_MC33_搬送モータ)
end if	'G00635
if ldp(clrPBSV58_シリンダ) then
    res(CNT_SV58_シリンダ)
end if	'G00649
if ldp(clrPBMC35_洗浄ポンプA) then
    res(CNT_MC35_洗浄ポンプA)
end if	'G00681
if ldp(clrPBMC36_洗浄ポンプB) then
    res(CNT_MC36_洗浄ポンプB)
end if	'G00682
if ldp(clrPBMC37_洗浄ポンプC) then
    res(CNT_MC37_洗浄ポンプC)
end if	'G00683
if ldp(clrPBMC38_洗浄ポンプD) then
    res(CNT_MC38_洗浄ポンプD)
end if	'G00684
if ldp(clrPBMC39_洗浄ポンプE) then
    res(CNT_MC39_洗浄ポンプE)
end if	'G00685
if ldp(clrPBMC1_インバータ用電源) then
    res(CNT_MC1_インバータ用電源)
end if	'G00686
if ldp(clrPBSV67_釜フタ押さえ下降A) then
    res(CNT_SV67_釜フタ押さえ下降A)
end if	'G00697
if ldp(clrPBSV68_釜フタ押さえ下降B) then
    res(CNT_SV68_釜フタ押さえ下降B)
end if	'G00698
if ldp(clrPBSV69_給湯電磁弁) then
    res(CNT_SV69_給湯電磁弁)
end if	'G00699
if ldp(clrPBSV70_蒸気電磁弁) then
    res(CNT_SV70_蒸気電磁弁)
end if	'G00700
if ldp(clrPBSV71_釜フタストッパ) then
    res(CNT_SV71_釜フタストッパ)
end if	'G00701
if ldp(clrPBSV72_下洗浄電磁弁) then
    res(CNT_SV72_下洗浄電磁弁)
end if	'G00702
if ldp(clrPBSV73_釜フタ押さえ下降A) then
    res(CNT_SV73_釜フタ押さえ下降A)
end if	'G00713
if ldp(clrPBSV74_釜フタ押さえ下降B) then
    res(CNT_SV74_釜フタ押さえ下降B)
end if	'G00714
if ldp(clrPBSV75_給湯電磁弁) then
    res(CNT_SV75_給湯電磁弁)
end if	'G00715
if ldp(clrPBSV76_蒸気電磁弁) then
    res(CNT_SV76_蒸気電磁弁)
end if	'G00716
if ldp(clrPBSV77_釜フタストッパ) then
    res(CNT_SV77_釜フタストッパ)
end if	'G00717
if ldp(clrPBSV78_下洗浄電磁弁) then
    res(CNT_SV78_下洗浄電磁弁)
end if	'G00718
if ldp(clrPBSV79_釜フタ押さえ下降A) then
    res(CNT_SV79_釜フタ押さえ下降A)
end if	'G00729
if ldp(clrPBSV80_釜フタ押さえ下降B) then
    res(CNT_SV80_釜フタ押さえ下降B)
end if	'G00730
if ldp(clrPBSV81_給湯電磁弁) then
    res(CNT_SV81_給湯電磁弁)
end if	'G00731
if ldp(clrPBSV82_蒸気電磁弁) then
    res(CNT_SV82_蒸気電磁弁)
end if	'G00732
if ldp(clrPBSV83_釜フタストッパ) then
    res(CNT_SV83_釜フタストッパ)
end if	'G00733
if ldp(clrPBSV84_下洗浄電磁弁) then
    res(CNT_SV84_下洗浄電磁弁)
end if	'G00734
if ldp(clrPBSV85_釜フタ押さえ下降A) then
    res(CNT_SV85_釜フタ押さえ下降A)
end if	'G00745
if ldp(clrPBSV86_釜フタ押さえ下降B) then
    res(CNT_SV86_釜フタ押さえ下降B)
end if	'G00746
if ldp(clrPBSV87_給湯電磁弁) then
    res(CNT_SV87_給湯電磁弁)
end if	'G00747
if ldp(clrPBSV88_蒸気電磁弁) then
    res(CNT_SV88_蒸気電磁弁)
end if	'G00748
if ldp(clrPBSV89_釜フタストッパ) then
    res(CNT_SV89_釜フタストッパ)
end if	'G00749
if ldp(clrPBSV90_下洗浄電磁弁) then
    res(CNT_SV90_下洗浄電磁弁)
end if	'G00750
if ldp(clrPBSV91_釜フタ押さえ下降A) then
    res(CNT_SV91_釜フタ押さえ下降A)
end if	'G00761
if ldp(clrPBSV92_釜フタ押さえ下降B) then
    res(CNT_SV92_釜フタ押さえ下降B)
end if	'G00762
if ldp(clrPBSV93_給湯電磁弁) then
    res(CNT_SV93_給湯電磁弁)
end if	'G00763
if ldp(clrPBSV94_蒸気電磁弁) then
    res(CNT_SV94_蒸気電磁弁)
end if	'G00764
if ldp(clrPBSV95_釜フタストッパ) then
    res(CNT_SV95_釜フタストッパ)
end if	'G00765
if ldp(clrPBSV96_下洗浄電磁弁) then
    res(CNT_SV96_下洗浄電磁弁)
end if	'G00766
if ldp(clrPBSV97_すすぎ電磁弁) then
    res(CNT_SV97_すすぎ電磁弁)
end if	'G00785
if ldp(clrPBSV98_仕上げ電磁弁) then
    res(CNT_SV98_仕上げ電磁弁)
end if	'G00786
if ldp(clrPBINV1_コンベアモータ正転) then
    res(CNT_INV1_コンベアモータ正転)
end if	'G00801
if ldp(clrPBINV1_コンベア異常) then
    res(CNT_INV1_コンベア異常)
end if	'G00802
if ldp(clrPBINV2_コンベアモータ正転) then
    res(CNT_INV2_コンベアモータ正転)
end if	'G00805
if ldp(clrPBINV2_コンベア異常) then
    res(CNT_INV2_コンベア異常)
end if	'G00806
if ldp(clrPBINV3_コンベアモータ正転) then
    res(CNT_INV3_コンベアモータ正転)
end if	'G00809
if ldp(clrPBINV3_コンベア異常) then
    res(CNT_INV3_コンベア異常)
end if	'G00810
if ldp(clrPBINV4_インバータ正転) then
    res(CNT_INV4_インバータ正転)
end if	'G00857
if ldp(clrPBINV4_インバータ停止) then
    res(CNT_INV4_インバータ停止)
end if	'G00858

if 0 then
'フタ釜インジケータ	'I00000
if PH51_フタ検知 and PH50_釜検知 then	'I00001
StageItem0=Item_釜	'I00002
else if not(PH51_フタ検知) and PH50_釜検知 then	'I00003
StageItem0=Item_釜ONフタOFF	'I00004
else if PH51_フタ検知 and  not(PH50_釜検知) then	'I00005
StageItem0=Item_フタ	'I00006
else if not(PH51_フタ検知) and  not(PH50_釜検知) then	'I00007
StageItem0=Item_空	'I00008
end if	'I00009
if PH2_フタ検知 and PH1_釜検知 then	'I00010
StageItem1=Item_釜	'I00011
else if not(PH2_フタ検知) and PH1_釜検知 then	'I00012
StageItem1=Item_釜ONフタOFF	'I00013
else if PH2_フタ検知 and  not(PH1_釜検知) then	'I00014
StageItem1=Item_フタ	'I00015
else if not(PH2_フタ検知) and  not(PH1_釜検知) then	'I00016
StageItem1=Item_空	'I00017
end if	'I00018
if PH4_フタ検知 and PH3_釜検知 then	'I00019
StageItem2=Item_釜	'I00020
else if not(PH4_フタ検知) and PH3_釜検知 then	'I00021
StageItem2=Item_釜ONフタOFF	'I00022
else if PH4_フタ検知 and  not(PH3_釜検知) then	'I00023
StageItem2=Item_フタ	'I00024
else if not(PH4_フタ検知) and  not(PH3_釜検知) then	'I00025
StageItem2=Item_空	'I00026
end if	'I00027
if PH53_フタ検知 and PH52_釜検知 then	'I00028
StageItem3=Item_釜	'I00029
else if not(PH53_フタ検知) and PH52_釜検知 then	'I00030
StageItem3=Item_釜ONフタOFF	'I00031
else if PH53_フタ検知 and  not(PH52_釜検知) then	'I00032
StageItem3=Item_フタ	'I00033
else if not(PH53_フタ検知) and  not(PH52_釜検知) then	'I00034
StageItem3=Item_空	'I00035
end if	'I00036
if PH6_フタ検知 and PH5_釜検知 then	'I00037
StageItem4=Item_釜	'I00038
else if not(PH6_フタ検知) and PH5_釜検知 then	'I00039
StageItem4=Item_釜ONフタOFF	'I00040
else if PH6_フタ検知 and  not(PH5_釜検知) then	'I00041
StageItem4=Item_フタ	'I00042
else if not(PH6_フタ検知) and  not(PH5_釜検知) then	'I00043
StageItem4=Item_空	'I00044
end if	'I00045
if PH12_フタ検知 and PH11_釜検知 then	'I00046
StageItem5=Item_釜	'I00047
else if not(PH12_フタ検知) and PH11_釜検知 then	'I00048
StageItem5=Item_釜ONフタOFF	'I00049
else if PH12_フタ検知 and  not(PH11_釜検知) then	'I00050
StageItem5=Item_フタ	'I00051
else if not(PH12_フタ検知) and  not(PH11_釜検知) then	'I00052
StageItem5=Item_空	'I00053
end if	'I00054
if PH14_フタ検知 and PH13_釜検知 then	'I00055
StageItem6=Item_釜	'I00056
else if not(PH14_フタ検知) and PH13_釜検知 then	'I00057
StageItem6=Item_釜ONフタOFF	'I00058
else if PH14_フタ検知 and  not(PH13_釜検知) then	'I00059
StageItem6=Item_フタ	'I00060
else if not(PH14_フタ検知) and  not(PH13_釜検知) then	'I00061
StageItem6=Item_空	'I00062
end if	'I00063
if PH16_フタ検知 and PH15_釜検知 then	'I00064
StageItem7=Item_釜	'I00065
else if not(PH16_フタ検知) and PH15_釜検知 then	'I00066
StageItem7=Item_釜ONフタOFF	'I00067
else if PH16_フタ検知 and  not(PH15_釜検知) then	'I00068
StageItem7=Item_フタ	'I00069
else if not(PH16_フタ検知) and  not(PH15_釜検知) then	'I00070
StageItem7=Item_空	'I00071
end if	'I00072
if PH18_フタ検知 and PH17_釜検知 then	'I00073
StageItem8=Item_釜	'I00074
else if not(PH18_フタ検知) and PH17_釜検知 then	'I00075
StageItem8=Item_釜ONフタOFF	'I00076
else if PH18_フタ検知 and  not(PH17_釜検知) then	'I00077
StageItem8=Item_フタ	'I00078
else if not(PH18_フタ検知) and  not(PH17_釜検知) then	'I00079
StageItem8=Item_空	'I00080
end if	'I00081
if PH20_フタ検知 and PH19_釜検知 then	'I00082
StageItem9=Item_釜	'I00083
else if not(PH20_フタ検知) and PH19_釜検知 then	'I00084
StageItem9=Item_釜ONフタOFF	'I00085
else if PH20_フタ検知 and  not(PH19_釜検知) then	'I00086
StageItem9=Item_フタ	'I00087
else if not(PH20_フタ検知) and  not(PH19_釜検知) then	'I00088
StageItem9=Item_空	'I00089
end if	'I00090
if PH58_釜検知前ステージ then	'I00091
StageItem10=Item_フタ釜	'I00092
else	'I00093
Stageitem10=Item_空	'I00094
end if	'I00095
if PH55_釜検知ステージ then	'I00100
StageItem11=Item_フタ釜	'I00101
else	'I00102
Stageitem11=Item_空	'I00103
end if	'I00104
if PH59_釜検知炊飯機入口 then	'I00109
StageItem12=Item_フタ釜	'I00110
else	'I00111
Stageitem12=Item_空	'I00112
end if	'I00113
if PH56_釜送りトリガ then	'I00118
StageItem13=Item_フタ釜	'I00119
else	'I00120
Stageitem13=Item_空	'I00121
end if	'I00122
if PH57_釜検知ステージ then	'I00127
StageItem14=Item_フタ釜	'I00128
else	'I00129
Stageitem14=Item_空	'I00130
end if	'I00131
if 0 then	'I00136
StageItem15=Item_フタ釜	'I00137
else	'I00138
Stageitem15=Item_空	'I00139
end if	'I00140
if PH21_むらし機出口センサ then	'I00145
StageItem16=Item_フタ釜	'I00146
else	'I00147
Stageitem16=Item_空	'I00148
end if	'I00149
if PH22_釜検知 then	'I00154
StageItem17=Item_フタ釜	'I00155
else	'I00156
Stageitem17=Item_空	'I00157
end if	'I00158
if PH24_フタ検知 and PH23_釜検知 then	'I00163
StageItem18=Item_釜	'I00164
else if not(PH24_フタ検知) and PH23_釜検知 then	'I00165
StageItem18=Item_釜ONフタOFF	'I00166
else if PH24_フタ検知 and  not(PH23_釜検知) then	'I00167
StageItem18=Item_フタ	'I00168
else if not(PH24_フタ検知) and  not(PH23_釜検知) then	'I00169
StageItem18=Item_空	'I00170
end if	'I00171
if PH26_フタ検知 and PH25_釜検知 then	'I00172
StageItem19=Item_釜	'I00173
else if not(PH26_フタ検知) and PH25_釜検知 then	'I00174
StageItem19=Item_釜ONフタOFF	'I00175
else if PH26_フタ検知 and  not(PH25_釜検知) then	'I00176
StageItem19=Item_フタ	'I00177
else if not(PH26_フタ検知) and  not(PH25_釜検知) then	'I00178
StageItem19=Item_空	'I00179
end if	'I00180
if PH28_フタ検知 and PH27_釜検知 then	'I00181
StageItem20=Item_釜	'I00182
else if not(PH28_フタ検知) and PH27_釜検知 then	'I00183
StageItem20=Item_釜ONフタOFF	'I00184
else if PH28_フタ検知 and  not(PH27_釜検知) then	'I00185
StageItem20=Item_フタ	'I00186
else if not(PH28_フタ検知) and  not(PH27_釜検知) then	'I00187
StageItem20=Item_空	'I00188
end if	'I00189
if PH30_フタ検知 and PH29_釜検知 then	'I00190
StageItem21=Item_釜	'I00191
else if not(PH30_フタ検知) and PH29_釜検知 then	'I00192
StageItem21=Item_釜ONフタOFF	'I00193
else if PH30_フタ検知 and  not(PH29_釜検知) then	'I00194
StageItem21=Item_フタ	'I00195
else if not(PH30_フタ検知) and  not(PH29_釜検知) then	'I00196
StageItem21=Item_空	'I00197
end if	'I00198
if PH31_釜検知 then	'I00199
StageItem22=Item_釜	'I00200
else	'I00201
Stageitem22=Item_空	'I00202
end if	'I00203
if PH33_フタ検知 and PH32_釜検知 then	'I00208
StageItem23=Item_釜	'I00209
else if not(PH33_フタ検知) and PH32_釜検知 then	'I00210
StageItem23=Item_釜ONフタOFF	'I00211
else if PH33_フタ検知 and  not(PH32_釜検知) then	'I00212
StageItem23=Item_フタ	'I00213
else if not(PH33_フタ検知) and  not(PH32_釜検知) then	'I00214
StageItem23=Item_空	'I00215
end if	'I00216
if PH35_フタ検知 and PH34_釜検知 then	'I00217
StageItem24=Item_釜	'I00218
else if not(PH35_フタ検知) and PH34_釜検知 then	'I00219
StageItem24=Item_釜ONフタOFF	'I00220
else if PH35_フタ検知 and  not(PH34_釜検知) then	'I00221
StageItem24=Item_フタ	'I00222
else if not(PH35_フタ検知) and  not(PH34_釜検知) then	'I00223
StageItem24=Item_空	'I00224
end if	'I00225
if PH37_フタ検知 and PH36_釜検知 then	'I00226
StageItem25=Item_釜	'I00227
else if not(PH37_フタ検知) and PH36_釜検知 then	'I00228
StageItem25=Item_釜ONフタOFF	'I00229
else if PH37_フタ検知 and  not(PH36_釜検知) then	'I00230
StageItem25=Item_フタ	'I00231
else if not(PH37_フタ検知) and  not(PH36_釜検知) then	'I00232
StageItem25=Item_空	'I00233
end if	'I00234
if PH38_釜検知 then	'I00235
StageItem26=Item_釜	'I00236
else	'I00237
Stageitem26=Item_空	'I00238
end if	'I00239
if 0 and 0 then	'I00244
StageItem27=Item_釜	'I00245
else if not(0) and 0 then	'I00246
StageItem27=Item_釜ONフタOFF	'I00247
else if 0 and  not(0) then	'I00248
StageItem27=Item_フタ	'I00249
else if not(0) and  not(0) then	'I00250
StageItem27=Item_空	'I00251
end if	'I00252
if PH49_フタ検知 and PH48_釜検知 then	'I00253
StageItem28=Item_釜	'I00254
else if not(PH49_フタ検知) and PH48_釜検知 then	'I00255
StageItem28=Item_釜ONフタOFF	'I00256
else if PH49_フタ検知 and  not(PH48_釜検知) then	'I00257
StageItem28=Item_フタ	'I00258
else if not(PH49_フタ検知) and  not(PH48_釜検知) then	'I00259
StageItem28=Item_空	'I00260
end if	'I00261
if PH44_フタ検知 and PH43_釜検知 then	'I00262
StageItem29=Item_釜	'I00263
else if not(PH44_フタ検知) and PH43_釜検知 then	'I00264
StageItem29=Item_釜ONフタOFF	'I00265
else if PH44_フタ検知 and  not(PH43_釜検知) then	'I00266
StageItem29=Item_フタ	'I00267
else if not(PH44_フタ検知) and  not(PH43_釜検知) then	'I00268
StageItem29=Item_空	'I00269
end if	'I00270
if PH46_フタ検知 and PH45_釜検知 then	'I00271
StageItem30=Item_釜	'I00272
else if not(PH46_フタ検知) and PH45_釜検知 then	'I00273
StageItem30=Item_釜ONフタOFF	'I00274
else if PH46_フタ検知 and  not(PH45_釜検知) then	'I00275
StageItem30=Item_フタ	'I00276
else if not(PH46_フタ検知) and  not(PH45_釜検知) then	'I00277
StageItem30=Item_空	'I00278
end if	'I00279
if shiftreg釜フタ判定1=$40 and shiftreg釜フタ判定1=$80 then	'I00280
StageItem31=Item_釜ONフタOFF	'I00281
else if not(shiftreg釜フタ判定1=$40) and shiftreg釜フタ判定1=$80 then	'I00282
StageItem31=Item_釜	'I00283
else if shiftreg釜フタ判定1=$40 and  not(shiftreg釜フタ判定1=$80) then	'I00284
StageItem31=Item_フタ	'I00285
else if not(shiftreg釜フタ判定1=$40) and  not(shiftreg釜フタ判定1=$80) then	'I00286
StageItem31=Item_空	'I00287
end if	'I00288
if shiftreg釜フタ判定2=$40 and shiftreg釜フタ判定2=$80 then	'I00289
StageItem32=Item_釜ONフタOFF	'I00290
else if not(shiftreg釜フタ判定2=$40) and shiftreg釜フタ判定2=$80 then	'I00291
StageItem32=Item_釜	'I00292
else if shiftreg釜フタ判定2=$40 and  not(shiftreg釜フタ判定2=$80) then	'I00293
StageItem32=Item_フタ	'I00294
else if not(shiftreg釜フタ判定2=$40) and  not(shiftreg釜フタ判定2=$80) then	'I00295
StageItem32=Item_空	'I00296
end if	'I00297
if shiftreg釜フタ判定3=$40 and shiftreg釜フタ判定3=$80 then	'I00298
StageItem33=Item_釜ONフタOFF	'I00299
else if not(shiftreg釜フタ判定3=$40) and shiftreg釜フタ判定3=$80 then	'I00300
StageItem33=Item_釜	'I00301
else if shiftreg釜フタ判定3=$40 and  not(shiftreg釜フタ判定3=$80) then	'I00302
StageItem33=Item_フタ	'I00303
else if not(shiftreg釜フタ判定3=$40) and  not(shiftreg釜フタ判定3=$80) then	'I00304
StageItem33=Item_空	'I00305
end if	'I00306
if shiftreg釜フタ判定4=$40 and shiftreg釜フタ判定4=$80 then	'I00307
StageItem34=Item_釜ONフタOFF	'I00308
else if not(shiftreg釜フタ判定4=$40) and shiftreg釜フタ判定4=$80 then	'I00309
StageItem34=Item_釜	'I00310
else if shiftreg釜フタ判定4=$40 and  not(shiftreg釜フタ判定4=$80) then	'I00311
StageItem34=Item_フタ	'I00312
else if not(shiftreg釜フタ判定4=$40) and  not(shiftreg釜フタ判定4=$80) then	'I00313
StageItem34=Item_空	'I00314
end if	'I00315
if shiftreg釜フタ判定5=$40 and shiftreg釜フタ判定5=$80 then	'I00316
StageItem35=Item_釜ONフタOFF	'I00317
else if not(shiftreg釜フタ判定5=$40) and shiftreg釜フタ判定5=$80 then	'I00318
StageItem35=Item_釜	'I00319
else if shiftreg釜フタ判定5=$40 and  not(shiftreg釜フタ判定5=$80) then	'I00320
StageItem35=Item_フタ	'I00321
else if not(shiftreg釜フタ判定5=$40) and  not(shiftreg釜フタ判定5=$80) then	'I00322
StageItem35=Item_空	'I00323
end if	'I00324
if PH8_フタ検知 and PH7_釜検知 then	'I00325
StageItem36=Item_釜	'I00326
else if not(PH8_フタ検知) and PH7_釜検知 then	'I00327
StageItem36=Item_釜ONフタOFF	'I00328
else if PH8_フタ検知 and  not(PH7_釜検知) then	'I00329
StageItem36=Item_フタ	'I00330
else if not(PH8_フタ検知) and  not(PH7_釜検知) then	'I00331
StageItem36=Item_空	'I00332
end if	'I00333
if PH10_フタ検知 and PH9_釜検知 then	'I00334
StageItem37=Item_釜	'I00335
else if not(PH10_フタ検知) and PH9_釜検知 then	'I00336
StageItem37=Item_釜ONフタOFF	'I00337
else if PH10_フタ検知 and  not(PH9_釜検知) then	'I00338
StageItem37=Item_フタ	'I00339
else if not(PH10_フタ検知) and  not(PH9_釜検知) then	'I00340
StageItem37=Item_空	'I00341
end if	'I00342
if PH40_フタ検知 and PH39_釜検知 then	'I00343
StageItem38=Item_釜	'I00344
else if not(PH40_フタ検知) and PH39_釜検知 then	'I00345
StageItem38=Item_釜ONフタOFF	'I00346
else if PH40_フタ検知 and  not(PH39_釜検知) then	'I00347
StageItem38=Item_フタ	'I00348
else if not(PH40_フタ検知) and  not(PH39_釜検知) then	'I00349
StageItem38=Item_空	'I00350
end if	'I00351
'フタ検知エラー検出	'J00000
if not(PH51_フタ検知) and timPH50_釜検知.B then	'J00001
almPH51_フタ検知=ON	'J00002
end if	'J00003
if not(PH2_フタ検知) and timPH1_釜検知.B then	'J00010
almPH2_フタ検知=ON	'J00011
end if	'J00012
if not(PH4_フタ検知) and timPH3_釜検知.B then	'J00019
almPH4_フタ検知=ON	'J00020
end if	'J00021
if not(PH53_フタ検知) and timPH52_釜検知.B then	'J00028
almPH53_フタ検知=ON	'J00029
end if	'J00030
if not(PH6_フタ検知) and timPH5_釜検知.B then	'J00037
almPH6_フタ検知=ON	'J00038
end if	'J00039
if not(PH12_フタ検知) and timPH11_釜検知.B then	'J00046
almPH12_フタ検知=ON	'J00047
end if	'J00048
if not(PH14_フタ検知) and timPH13_釜検知.B then	'J00055
almPH14_フタ検知=ON	'J00056
end if	'J00057
if not(PH16_フタ検知) and timPH15_釜検知.B then	'J00064
almPH16_フタ検知=ON	'J00065
end if	'J00066
if not(PH18_フタ検知) and timPH17_釜検知.B then	'J00073
almPH18_フタ検知=ON	'J00074
end if	'J00075
if not(PH20_フタ検知) and timPH19_釜検知.B then	'J00082
almPH20_フタ検知=ON	'J00083
end if	'J00084
if not(PH24_フタ検知) and timPH23_釜検知.B then	'J00163
almPH24_フタ検知=ON	'J00164
end if	'J00165
if not(PH26_フタ検知) and timPH25_釜検知.B then	'J00172
almPH26_フタ検知=ON	'J00173
end if	'J00174
if not(PH28_フタ検知) and timPH27_釜検知.B then	'J00181
almPH28_フタ検知=ON	'J00182
end if	'J00183
if not(PH30_フタ検知) and timPH29_釜検知.B then	'J00190
almPH30_フタ検知=ON	'J00191
end if	'J00192
if not(PH33_フタ検知) and timPH32_釜検知.B then	'J00208
almPH33_フタ検知=ON	'J00209
end if	'J00210
if not(PH35_フタ検知) and timPH34_釜検知.B then	'J00217
almPH35_フタ検知=ON	'J00218
end if	'J00219
if not(PH37_フタ検知) and timPH36_釜検知.B then	'J00226
almPH37_フタ検知=ON	'J00227
end if	'J00228
if not(PH49_フタ検知) and timPH48_釜検知.B then	'J00253
almPH49_フタ検知=ON	'J00254
end if	'J00255
if not(PH44_フタ検知) and timPH43_釜検知.B then	'J00262
almPH44_フタ検知=ON	'J00263
end if	'J00264
if not(PH46_フタ検知) and timPH45_釜検知.B then	'J00271
almPH46_フタ検知=ON	'J00272
end if	'J00273
if not(PH8_フタ検知) and timPH7_釜検知.B then	'J00325
almPH8_フタ検知=ON	'J00326
end if	'J00327
if not(PH10_フタ検知) and timPH9_釜検知.B then	'J00334
almPH10_フタ検知=ON	'J00335
end if	'J00336
if not(PH40_フタ検知) and timPH39_釜検知.B then	'J00343
almPH40_フタ検知=ON	'J00344
end if	'J00345
end if