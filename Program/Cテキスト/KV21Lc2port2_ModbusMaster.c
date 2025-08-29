'KV21Lc2port2_ModbusMaster

if CR2008 then

'------------------------------------------
' �e�ƯĂ�ModbusID�o�^
'------------------------------------------
	AD4410c1=#1
	AD4410c2=#2
	AD4532c1=#10


'�g�p����(1)  �g�p���Ȃ�(0)
	AD4410c1USE=0
	AD4410c2USE=0
	AD4532c1USE=1

end if
'------------------------------------------
' KV-L21V�̃A�h���X
' R39000
' DM11000
'------------------------------------------
'port1
	'�@KV BUILDER �Ŏg�p
	'��L�� R (1ch) 16�� 	DM 0��
	'�AMODBUS MASTER �Ŏg�p
	'��L�� R (2ch) 32�� 	DM 600��

'port2
	Z3=390*16 + (1*16)	'port2 rlay�̐擪���ڽ
	Z4=11000 + (0) 'port2 DM�̐擪���ڽ


'---------------------------------------------------------

'------------------------------------------
'Modbus Master Addres Map
'------------------------------------------
'KV-L21V	KV-N10L
'------------------------------------------
'R001:Z3	CR6601	����ޑ��M
'R004:Z3	CR6604	�ʐM�ݒ�ύX�v��
'R101:Z3	CR6701	���s����
'R102:Z3	CR6702	���s���s
'R103:Z3	CR6703	���s��
'R104:Z3	CR6704	�ʐM�ݒ�ύX����
'R108:Z3	CR6708	ER���
'R109:Z3	CR6709	CD���
'R110:Z3	CR6710	DR���
'R111:Z3	CR6711	RS���
'R112:Z3	CR6712	CS���
'------------------------------------------
'DM20000	�G���[�R�[�h
'DM001:Z4	CM6001	�ڰ�ދǔ�
'DM002:Z4	CM6002	̧ݸ��ݺ���
'DM003:Z4	CM6003	���̧ݸ��ݺ���
'DM006:Z4	CM6006	�ް��i�[�P��
'DM007:Z4	CM6007	�ǂݏo���擪���ڽ
'DM008:Z4	CM6008	�ǂݏo���_��
'DM310:Z4	CM6310	�ǂݏo���޲Đ�
'DM311~563:Z4	CM6311~CM6563	�ǂݏo��Buff[0] ~ [252]
'DM009:Z4		CM6009	�������ݐ擪���ڽ
'DM010:Z4		CM6010	�������ݓ_��
'DM011~263:Z4	CM6011~CM6263	���������ް�Buff[0] ~ [252]
'DM300:Z4	CM6300	�װ����
'------------------------------------------
'DM570:Z4	CM6570	��M��ѱ��
'DM571:Z4	CM6571	���M����
'DM572:Z4	CM6572	��ײ��
'DM573:Z4	CM6573	��ײ����
'DM574:Z4	CM6574	��۰�޷����ިڲ���
'DM580:Z4	CM6580	�ݒ�ςݎ�M��ѱ��
'DM581:Z4	CM6581	�ݒ�ςݑ��M����
'DM582:Z4	CM6582	�ݒ�ς���ײ��
'DM583:Z4	CM6583	�ݒ�ς���ײ����
'DM584:Z4	CM6584	�ݒ�ς���۰�޷����ިڲ���
'------------------------------------------


	'2�b�ȓ��ɐڑ���������ꂽ��G���[���N���A���ĉ񕜂���
	if  errcode=0 and DispMsg1Item<>0 then
		tmr(true, retry_reset_wait, 20)
		if retry_reset_wait.B then
			DispMsg1Item=0
		end if
	else
		res(true,retry_reset_wait.B)
	end if


	'--------------------------
	if AD4410c1USE=1 and not(DispMsg1Item=AD4410c1) then
		AD4410c1Act=1
	else
		AD4410c1Act=0
	end if
	'--------------------------
	if AD4410c2USE=1 and not(DispMsg1Item=AD4410c2) then
		AD4410c2Act=1
	else
		AD4410c2Act=0
	end if
	'--------------------------
	if AD4532c1USE=1 and not(DispMsg1Item=AD4532c1) then
		AD4532c1Act=1
	else
		AD4532c1Act=0
	end if
	'--------------------------
	ModbusC2AlmID=DispMsg1Item

	flgADR4410c1_RegEdit=1
	flgADR4410c2_RegEdit=1
	flgADR4532c1_RegEdit=1

'------------------------------------------
' �ʐM�ݒ�ύX
'------------------------------------------
' �쓮�ض�  CR2008 �d��ON��
' R004:Z3	�ʐM�ݒ�ύX�v��
' R104:Z3	�ʐM�ݒ�ύX����

	if CR2008 then

		DM570:Z4=10	'��M��ѱ�� (�����l 0:10�`2000[�~10ms])
		DM571:Z4=0	'���M���� (�����l x10ms)
		DM572:Z4=2	'��ײ�� (�����l 0��)
		DM573:Z4=20	'��ײ���� (�����l 0:1�`1000[�~10ms] �����l 0 �̏ꍇ300mSec)
		DM574:Z4=200	'��۰�޷����ިڲ��� (�����l 200)

		'--- �ǂݏo����p �i�[ڼ޽� ---
		'DM580:Z4	'�ݒ�ςݎ�M��ѱ��
		'DM581:Z4	'�ݒ�ςݑ��M�������
		'DM582:Z4	'�ݒ�ς���ײ����
		'DM583:Z4	'�ݒ�ς���ײ�������
		'DM584:Z4	'�ݒ�ς���۰�޷��ĳ������

		R004:Z3 = ON

	end if
	
	if LDP(R104:Z3) then
		R004:Z3 = OFF
	end if
'------------------------------------------
'Modbus���ı�����ϰ
'------------------------------------------
	if not(ModbusStartWait) then
		if ldp(CR2006) then	'1s
			if ModbusStartWaitTim<3 then
				inc(ModbusStartWaitTim)
			else 
				ModbusStartWait=true
			end if
 		end if
	end if 
'---------------------------------------------------------------------------
' KV-L21V ����M
'---------------------------------------------------------------------------
	'-----------------------------------------------------------------------
	select case readstep  '�ǂݍ��ݏ���
	'-----------------------------------------------------------------------
		case 0
		'-------------------------------------------------------------------
		'�R�C���ǂݏo�� [01]
		'ModbusID : �X���[�uID
		'ReadAdr : �ǂݏo���擪���ڽ
		'ReadCnt : �A������R�C���̓_��
		'adrset(true,xxx,readstackptr) :�f�[�^���i�[������ڽ
		'-------------------------------------------------------------------
		case 10
			if not(R101:Z3) and not(R102:Z3) and not(R103:Z3) then
			
				DM006:Z4=0 '16bit�P��
				DM001:Z4=ModbusID
				DM002:Z4=#1
				DM007:Z4=ReadAdr
				DM008:Z4=ReadCnt

				R001:Z3 = ON
				inc(readstep)
			end if
		case 11
			if LDP(R101:Z3) and not(R103:Z3) then

				if not(R102:Z3) then
					*readstackptr=DM311:Z4
				end if
				if R102:Z3 then
					errcode = DM300:Z4
				end if
				
				R001:Z3= OFF
				inc(readstep)
			end if
		case 12
			readstep=0
		'-------------------------------------------------------------------
		'���͓ǂݏo�� [02]
		'ModbusID : �X���[�uID
		'ReadAdr : �ǂݏo���擪���ڽ
		'ReadCnt : �A�����郌�W�X�^�̓_��
		'adrset(true,xxx,readstackptr) :�f�[�^���i�[������ڽ
		'-------------------------------------------------------------------
		case 20
			if not(R101:Z3) and not(R102:Z3) and not(R103:Z3) then
			
				DM006:Z4=0 '16bit�P��
				DM001:Z4=ModbusID
				DM002:Z4=#2
				DM007:Z4=ReadAdr
				DM008:Z4=ReadCnt

				R001:Z3 = ON
				inc(readstep)
			end if
		case 21
			if LDP(R101:Z3) and not(R103:Z3) then

				if not(R102:Z3) then
					readstackcnt=asra(DM310:Z4,1)
					adrset(true,DM311:Z4,readbuffptr)
					for loopi=1 to readstackcnt step 1
						*readstackptr=*readbuffptr
						adrinc(readstackptr)
						adrinc(readbuffptr)
					next
				end if
				if R102:Z3 then
					errcode = DM300:Z4
				end if
				
				R001:Z3= OFF
				inc(readstep)
			end if
		case 22
			readstep=0
		'-------------------------------------------------------------------
		'�ێ����W�X�^�̘A���ǂݏo�� [03]
		'ModbusID : �X���[�uID
		'ReadAdr : �ǂݏo���擪���ڽ
		'ReadCnt : �A�����郌�W�X�^�̓_��
		'adrset(true,xxx,readstackptr) :�f�[�^���i�[������ڽ
		'-------------------------------------------------------------------
		case 30
			if not(R101:Z3) and not(R102:Z3) and not(R103:Z3) then

				DM006:Z4=0 '16bit�P��
				DM001:Z4=ModbusID
				DM002:Z4=#3
				DM007:Z4=ReadAdr
				DM008:Z4=ReadCnt
				
				R001:Z3 = ON
				inc(readstep)
			end if
		case 31
			if LDP(R101:Z3) and not(R103:Z3) then

				if not(R102:Z3) then
					readstackcnt=asra(DM310:Z4,1)
					adrset(true,DM311:Z4,readbuffptr)
					for loopi=1 to readstackcnt step 1
						*readstackptr=*readbuffptr
						adrinc(readstackptr)
						adrinc(readbuffptr)
					next
				end if
				if R102:Z3 then
					errcode = DM300:Z4
				end if
				
				R001:Z3= OFF
				inc(readstep)
			end if
		case 32
			readstep=0

		'-------------------------------------------------------------------
		'���̓��W�X�^�̘A���ǂݏo�� [04]
		'ModbusID : �X���[�uID
		'ReadAdr : �ǂݏo���擪���ڽ
		'ReadCnt : �A�����郌�W�X�^�̓_��
		'adrset(true,xxx,readstackptr) :�f�[�^���i�[������ڽ
		'-------------------------------------------------------------------
		case 40
			if not(R101:Z3) and not(R102:Z3) and not(R103:Z3) then

				DM006:Z4=0 '16bit�P��
				DM001:Z4=ModbusID
				DM002:Z4=#4
				DM007:Z4=ReadAdr
				DM008:Z4=ReadCnt

				R001:Z3 = ON
				inc(readstep)
			end if
		case 41
			if LDP(R101:Z3) and not(R103:Z3) then

				if not(R102:Z3) then

					readstackcnt=asra(DM310:Z4,1)
					adrset(true,DM311:Z4,readbuffptr)
					for loopi=1 to readstackcnt step 1
						*readstackptr=*readbuffptr
						adrinc(readstackptr)
						adrinc(readbuffptr)
					next
				end if
				if R102:Z3 then
					errcode = DM300:Z4
				end if
				
				R001:Z3= OFF
				inc(readstep)
			end if
		case 42
			readstep=0


	end select

	'-----------------------------------------------------------------------
	select case writestep '�������ݏ���
	'-----------------------------------------------------------------------
		case 0
		
		'-------------------------------------------------------------------
		'�R�C��1�_�������� [05]
		'ModbusID : �X���[�uID
		'WriteAdr : �������݃R�C�����ڽ
		'setCoilval : �R�C���̐ݒ�l setCoilval [ off(0)  or on(not 0) ]
		'-------------------------------------------------------------------
		case 10
			if not(R101:Z3) and not(R102:Z3) and not(R103:Z3) then

				DM006:Z4=0 '16bit�P��
				DM001:Z4=ModbusID
				DM002:Z4=#5
				DM009:Z4=WriteAdr
				DM011:Z4=setCoilval
				
				R001:Z3 = ON
				inc(writestep)
			end if
		case 11
			if LDP(R101:Z3) and not(R103:Z3) then

				if not(R102:Z3) then
					''*getvalptr = *setvalptr
				end if
				if R102:Z3 then
					errcode = DM300:Z4
				end if
				
				R001:Z3= OFF
				inc(writestep)
			end if
		case 12
			writestep=0

		'-------------------------------------------------------------------
		'�R�C���A���������� [15 ($0F)]
		'ModbusID : �X���[�uID
		'WriteAdr : �������݃R�C�����ڽ
		'WriteCnt �F�������݃R�C����(�r�b�g���j
		'adrset(true, xxx, setvalptr) : �������݃R�C���l�i16bit���W�X�^�j
		'-------------------------------------------------------------------
		case 20
			if not(R101:Z3) and not(R102:Z3) and not(R103:Z3) then

				DM006:Z4=0 '16bit�P��
				DM001:Z4=ModbusID
				DM002:Z4=#15
				DM009:Z4=WriteAdr
				DM010:Z4=WriteCnt
				DM011:Z4=*setvalptr'(�ő��16��z��j

				R001:Z3 = ON
				inc(writestep)
			end if
		case 21
			if LDP(R101:Z3) and not(R103:Z3) then

				if not(R102:Z3) then
					'*getvalptr = *setvalptr
				end if
				if R102:Z3 then
					errcode = DM300:Z4
				end if
				
				R001:Z3= OFF
				inc(writestep)
			end if
		case 22
			writestep=0
		'-------------------------------------------------------------------
		'�ێ����W�X�^1�_�������� [6]
		'ModbusID : �X���[�uID
		'WriteAdr : �������ݱ��ڽ
		'adrset(true, xxx, setvalptr) : �������݃��W�X�^�l�i16bit���W�X�^�j
		'-------------------------------------------------------------------
		case 30
			if not(R101:Z3) and not(R102:Z3) and not(R103:Z3) then

				DM006:Z4=0 '16bit�P��
				DM001:Z4=ModbusID
				DM002:Z4=#6
				DM009:Z4=WriteAdr
				DM011:Z4=*setvalptr

				R001:Z3 = ON
				inc(writestep)
			end if
		case 31
			if LDP(R101:Z3) and not(R103:Z3) then

				if not(R102:Z3) then
					'*getvalptr = *setvalptr
				end if
				if R102:Z3 then
					errcode = DM300:Z4
				end if
				
				R001:Z3= OFF
				inc(writestep)
			end if
		case 32
			writestep=0
		'-------------------------------------------------------------------
		'�ێ����W�X�^�A���������� [16 (0x10)]
		'ModbusID : �X���[�uID
		'WriteAdr : �������ݐ擪���ڽ
		'WriteCnt �F�������݃��W�X�^�i16bit���W�X�^�j��
		'adrset(true, xxx, setvalptr) : �������݃��W�X�^�擪���ڽ�i16bit���W�X�^�j
		'-------------------------------------------------------------------
		case 40
			if not(R101:Z3) and not(R102:Z3) and not(R103:Z3) then

				DM006:Z4=0 '16bit�P��
				DM001:Z4=ModbusID
				DM002:Z4=#16
				DM009:Z4=WriteAdr
				DM010:Z4=WriteCnt

				adrset(true, DM011:Z4, writebuffptr)
				for loopi=1 to WriteCnt step 1
					*writebuffptr=*setvalptr
					adrinc(writebuffptr)
					adrinc(setvalptr)
				next


				R001:Z3 = ON
				inc(writestep)
			end if
		case 41
			if LDP(R101:Z3) and not(R103:Z3) then

				if not(R102:Z3) then
					'*getvalptr = *setvalptr
				end if
				if R102:Z3 then
					errcode = DM300:Z4
				end if
				
				R001:Z3= OFF
				inc(writestep)
			end if
		case 42
			writestep=0
		'-------------------------------------------------------------------

	end select

'------------------------------------------
' �d��ON���̏�����
'------------------------------------------

	if CR2008 then
	
		'--------------------------
		' �׸޸ر
		'--------------------------
		errcode =0
		comstep =0
		readstep =0
		writestep =0
		setcoilstep=0
		
		getvalptr =0
		setvalptr =0
		readstackptr =0
		ReadAdr =0
		WriteAdr =0
		ModbusID =0

		'--------------------------
		'���̓��W�X�^��0�N���A
		'--------------------------
		getADR4532c1_Decimal=0
		getADR4532c1_Unit=0
		getADR4532c1_Raw=0
		getADR4532c1_Sampl=0

		'--------------------------
		'�ێ����W�X�^�̓ǂݎ��l������
		'--------------------------
		getADR4410c1_NearZero=0
		getADR4410c1_Up=0
		getADR4410c1_Low=0

		getADR4410c2_NearZero=0
		getADR4410c2_Up=0
		getADR4410c2_Low=0

		getADR4532c1_Up=0
		getADR4532c1_Low=0
		getADR4532c1_Up1=0
		getADR4532c1_Low1=0
		getADR4532c1_Up2=0
		getADR4532c1_Low2=0
		getADR4532c1_Up3=0
		getADR4532c1_Low3=0
		getADR4532c1_Up4=0
		getADR4532c1_Low4=0
		getADR4532c1_Up5=0
		getADR4532c1_Low5=0
		getADR4532c1_Starttime1=0
		getADR4532c1_Endtime1=0
		getADR4532c1_Starttime2=0
		getADR4532c1_Endtime2=0
		getADR4532c1_Starttime3=0
		getADR4532c1_Endtime3=0
		getADR4532c1_Starttime4=0
		getADR4532c1_Endtime4=0
		getADR4532c1_Starttime5=0
		getADR4532c1_Endtime5=0
		getADR4532c1_Offset=0
		getADR4532c1_NearZero=0
		getADR4532c1_Hys=0
		getADR4532c1_HysTime=0
		getADR4532c1_HysMode=0
		getADR4532c1_HoldTime=0
		getADR4532c1_CompMode=0

		'--------------------------
		ModbusStartWaitTim=0
		ModbusStartWait=false
		
	end if

'------------------------------------------
'�ʐM����Ւf��(xxxAct=0),���ݒl��0�N���A
'------------------------------------------

if AD4410c1Act=0 then
	getADR4410c1_Unit=0
	getADR4410c1_Decimal=0
	getADR4410c1_����=0
	getADR4410c1_����=0
	getADR4410c1_����=0
	getADR4410c1_Stat1=0
	getADR4410c1_Stat2=0
	getADR4410c1_Stat3=0
end if

if AD4410c2Act=0 then
	getADR4410c2_Unit=0
	getADR4410c2_Decimal=0
	getADR4410c2_����=0
	getADR4410c2_����=0
	getADR4410c2_����=0
	getADR4410c2_Stat1=0
	getADR4410c2_Stat2=0
	getADR4410c2_Stat3=0
end if

if AD4532c1Act=0 then
	getADR4532c1_Decimal=0
	getADR4532c1_Unit=0
	getADR4532c1_Raw=0
	getADR4532c1_Sampl=0
end if

'------------------------------------------------------------------------------
' �ʐM�H��
'------------------------------------------------------------------------------

tms(true, msec_wait, msec_wait_val)


	'--------------------------------------------------------------------------
	if ModbusStartWait=true and errcode= 0 then '�d�����ԑ҂� and �ʐM�װ�Ȃ�
	'--------------------------------------------------------------------------
	
		if  readstep=0 and writestep=0 then
			'------------------------------------------------------------------
			select case comstep '����M�H��
			'------------------------------------------------------------------
			'------------------------------------------------------------------
			'AD4410c1
			'------------------------------------------------------------------
				case 0
					if AD4410c1Act=0 then
						comstep=7
					else 
						inc(comstep)
					end if
				case 1
					'AD4410
					'�o�̓R�C���̓ǂݍ���
					if 0 then
						ModbusID=AD4410c1
						ReadAdr=1
						ReadCnt=16
						adrset(true,getADR4410c1_Output,readstackptr)
						readstep=Func01
					end if					
					inc(comstep)
				case 2
					'�o�̓R�C���̏�������
					if AD4410c1Act<>0 then
						ModbusID=AD4410c1
						WriteAdr=0
						WriteCnt=16 '�r�b�g��
						adrset(true, setADR4410c1_Output, setvalptr)
						writestep=Func15
					end if
					inc(comstep)
				case 3
					'���̓��W�X�^�̓ǂݍ���
					if AD4410c1Act<>0 then
						ModbusID=AD4410c1
						ReadAdr=ADR4410_Unit
						ReadCnt=11 '���W�X�^��
						adrset(true,getADR4410c1_Unit,readstackptr)
						readstep=Func04
					end if
					inc(comstep)

				case 4
					'�ێ����W�X�^�̓ǂݍ���
					if AD4410c1Act<>0 then
						if flgADR4410c1_RegEdit<>0 then					'�ҏW�\�^�C�~���O
							ModbusID=AD4410c1
							ReadAdr=ADR4410_NearZero_L
							ReadCnt=6 '���W�X�^��
							adrset(true,getADR4410c1_NearZero,readstackptr)
							readstep=Func03
						end if
					end if
					inc(comstep)

				case 5
				
					'�ێ����W�X�^�̏�������
					if AD4410c1Act<>0 then

						if flgADR4410c1_RegEdit<>0 then
							ModbusID=AD4410c1
							adrset(true,getADR4410c1_NearZero,getvalptr)
							adrset(true,setADR4410c1_NearZero,setvalptr)
							for loopi=0 to 5 step 1
								if *getvalptr<>*setvalptr then
									WriteAdr=ADR4410_NearZero_L + loopi
									WriteCnt=1
									writestep=Func16
								break
									else
									adrinc(getvalptr)
									adrinc(setvalptr)
								end if
							next
						end if
					
					end if

					inc(comstep)
				case 6
					inc(comstep)
			'------------------------------------------------------------------
			'AD4410c2
			'------------------------------------------------------------------
				case 7
					if AD4410c2Act=0 then
						comstep=14
					else 
						inc(comstep)
					end if
				case 8
					'AD4410
					'�o�̓R�C���̓ǂݍ���
					if 0 then
						ModbusID=AD4410c2
						ReadAdr=1
						ReadCnt=16
						adrset(true,getADR4410c2_Output,readstackptr)
						readstep=Func01
					end if
					inc(comstep)

				case 9
					'�o�̓R�C���̏�������
					if AD4410c2Act<>0 then
						ModbusID=AD4410c2
						WriteAdr=0
						WriteCnt=16 '�r�b�g��
						adrset(true, setADR4410c2_Output, setvalptr)
						writestep=Func15
					end if
					inc(comstep)

				case 10
					'���̓��W�X�^�̓ǂݍ���
					if AD4410c2Act<>0 then
						ModbusID=AD4410c2
						ReadAdr=ADR4410_Unit
						ReadCnt=11 '���W�X�^��
						adrset(true,getADR4410c2_Unit,readstackptr)
						readstep=Func04
					end if
					inc(comstep)

				case 11
					'�ێ����W�X�^�̓ǂݍ���
					if AD4410c2Act<>0 then
						if flgADR4410c2_RegEdit<>0 then					'�ҏW�\�^�C�~���O
							ModbusID=AD4410c2
							ReadAdr=ADR4410_NearZero_L
							ReadCnt=6 '���W�X�^��
							adrset(true,getADR4410c2_NearZero,readstackptr)
							readstep=Func03
						end if
					end if
					inc(comstep)

				case 12
					'�ێ����W�X�^�̏�������
					if AD4410c2Act<>0 then
						if flgADR4410c2_RegEdit<>0 then
							ModbusID=AD4410c2
							adrset(true,getADR4410c2_NearZero,getvalptr)
							adrset(true,setADR4410c2_NearZero,setvalptr)
							for loopi=0 to 5 step 1
								if *getvalptr<>*setvalptr then
									WriteAdr=ADR4410_NearZero_L + loopi
									WriteCnt=1
									writestep=Func16
								break
									else
									adrinc(getvalptr)
									adrinc(setvalptr)
								end if
							next
						end if
					end if
					inc(comstep)
				case 13
					inc(comstep)

			'------------------------------------------------------------------
			'AD4532c1
			'------------------------------------------------------------------
				case 14
					if AD4532c1Act=0 then
						comstep=25
					else
						inc(comstep)
					end if
				case 15
					'AD4532
					'�o�̓R�C���̓ǂݍ���
					if 0 then
						ModbusID=AD4532c1
						ReadAdr=0
						ReadCnt=5
						adrset(true,getADR4532c1_Output,readstackptr)
						readstep=Func01
					end if
					
					inc(comstep)

				case 16
					'�o�̓R�C���̏�������
					if AD4532c1Act<>0 then
					
						select case setcoilstep 
						case 0
							if 1 then
								ModbusID=AD4532c1
								WriteAdr=ADR4532_SetHold
								setCoilval=anda(setADR4532c1_Output,2^0)
								writestep=Func05
							end if
								inc(setcoilstep)
						case 1
							if 1 then
								ModbusID=AD4532c1
								WriteAdr=ADR4532_ClrHold
								setCoilval=anda(setADR4532c1_Output,2^1)
								writestep=Func05
							end if
								inc(setcoilstep)
						case 2
							if 1 then
								ModbusID=AD4532c1
								WriteAdr=ADR4532_SetZero
								setCoilval=anda(setADR4532c1_Output,2^2)
								writestep=Func05
							end if
								inc(setcoilstep)
						case 3
							if 1 then
								ModbusID=AD4532c1
								WriteAdr=ADR4532_ClrZero
								setCoilval=anda(setADR4532c1_Output,2^3)
								writestep=Func05
							end if
								inc(setcoilstep)
						case 4
								setcoilstep=0
								inc(comstep)
						end select
					else
						setcoilstep=0
						inc(comstep)
					end if					

				case 17
					'���̓X�e�[�^�X�̓ǂݍ���
					if AD4532c1Act<>0 then
						ModbusID=AD4532c1
						ReadAdr=ADR4532_Hold
						ReadCnt=23 '�r�b�g��
						adrset(true,getADR4532c1_InputL,readstackptr)
						readstep=Func02
					end if
					inc(comstep)

				case 18
					'���̓��W�X�^�̓ǂݍ���
					if AD4532c1Act<>0 then
						ModbusID=AD4532c1
						ReadAdr=ADR4532_Decimal
						ReadCnt=6 '���W�X�^��
						adrset(true,getADR4532c1_Decimal,readstackptr)
						readstep=Func04
					end if
					inc(comstep)

				case 19
					'�ێ����W�X�^�̓ǂݍ���
					if AD4532c1Act<>0  then 
						if flgADR4532c1_RegEdit<>0 then
							ModbusID=AD4532c1
							ReadAdr=ADR4532_Up_L
							ReadCnt=24
							adrset(true,getADR4532c1_Up,readstackptr)
							readstep=Func03
						end if
					end if
					inc(comstep)

				case 20
					if AD4532c1Act<>0 and 0 then
						if flgADR4532c1_RegEdit<>0 then
							ModbusID=AD4532c1
							ReadAdr=ADR4532_Starttime1_L
							ReadCnt=20
							adrset(true,getADR4532c1_Starttime1,readstackptr)
							readstep=Func03
						end if
					end if
					inc(comstep)
				case 21
					if AD4532c1Act<>0 and 0 then
						if flgADR4532c1_RegEdit<>0 then
							ModbusID=AD4532c1
							ReadAdr=ADR4532_Offset_L
							ReadCnt=10
							adrset(true,getADR4532c1_Offset,readstackptr)
							readstep=Func03
						end if
					end if
					inc(comstep)

				case 22
					'�ێ����W�X�^�̏�������
					if AD4532c1Act<>0 then
						if flgADR4532c1_RegEdit<>0 then 
							ModbusID=AD4532c1
							adrset(true,getADR4532c1_Up,getvalptr)
							adrset(true,setADR4532c1_Up,setvalptr)
							for loopi=0 to 23 step 1
								if *getvalptr<>*setvalptr then
									WriteAdr=ADR4532_Up_L+loopi
									WriteCnt=1
									writestep=Func16
									break
								else
									adrinc(getvalptr)
									adrinc(setvalptr)
								end if
							next
						end if
					end if
					inc(comstep)
				case 23
					if AD4532c1Act<>0 and 0 then
						if flgADR4532c1_RegEdit<>0 then
							ModbusID=AD4532c1
							adrset(true,getADR4532c1_Starttime1,getvalptr)
							adrset(true,setADR4532c1_Starttime1,setvalptr)
							for loopi=0 to 19 step 1
								if *getvalptr<>*setvalptr then
									WriteAdr=ADR4532_Starttime1_L + loopi
									WriteCnt=1
									writestep=Func16
									break
								else
									adrinc(getvalptr)
									adrinc(setvalptr)
								end if
							next
						end if
					end if
					inc(comstep)

				case 24
					if AD4532c1Act<>0 and 0 then

						if flgADR4532c1_RegEdit<>0 then
							ModbusID=AD4532c1
							adrset(true,getADR4532c1_Offset,getvalptr)
							adrset(true,setADR4532c1_Offset,setvalptr)
							for loopi=0 to 9 step 1
								if *getvalptr<>*setvalptr then
									WriteAdr=ADR4532_Offset_L + loopi
									WriteCnt=1
									writestep=Func16
								break
									else
									adrinc(getvalptr)
									adrinc(setvalptr)
								end if
							next
						end if
						
					end if
					inc(comstep)

				case 25
					comstep=100

				'--------------------------------------------------------------
				case 100
					comstep=0
			end select
		
		end if 'if witestep=0 and readstep=0 
	'-----------------------------------------------------------------------
	' �ʐM�װ���o
	'-----------------------------------------------------------------------
	else

		if errcode<>0 then
			DispMsg1Item=ModbusID
		
		
			select case errcode
			
			case $0001	'�ڰ�ދǂ����Ή���̧ݸ��݂𑗐M���܂����B
				ErrCodeNo=1000+1
				DispMsg2Item= 10
				DispMsg3Item= 11
			case $0002	'�ڰ�ދǂ����Ή������޲��𑗐M���܂����B
				ErrCodeNo=1000+2
				DispMsg2Item= 12
				DispMsg3Item= 13
			case $0003	'�ڰ�ދǂ����Ή��̓ǂݏ����_���𑗐M���܂����B
				ErrCodeNo=1000+3
				DispMsg2Item= 14
				DispMsg3Item= 15
			case $0004	'�ڰ�ދǂ����A�ł��Ȃ���ԂɂȂ��Ă��܂��B
				ErrCodeNo=1000+4
				DispMsg2Item= 16
				DispMsg3Item= 17
			case $0101	'�ڰ�ޱ��ڽ�װ
				ErrCodeNo=1000+101
				DispMsg2Item= 18
				DispMsg3Item= 19
			case $0102	'̧ݸ��ݴװ
				ErrCodeNo=1000+102
				DispMsg2Item= 20
				DispMsg3Item= 21
			case $0103	'��فA���޲����ڽ�װ
				ErrCodeNo=1000+103
				DispMsg2Item= 22
				DispMsg3Item= 23
			case $0201	'ڽ��ݽ����޴װ
				ErrCodeNo=1000+201
				DispMsg2Item= 24
				DispMsg3Item= 25
			case $0301	'ڽ��ݽ�ڰѴװ�Aɲ�ޓ��ɂ��װ
				ErrCodeNo=1000+301
				DispMsg2Item= 26
				DispMsg3Item= 27
			case $0302	'
				ErrCodeNo=1000+302
				DispMsg2Item= 28
				DispMsg3Item= 29
			case $0401	'�������F�ڰ�ނ̒ʐM���Ұ��A�ʐM���x�Ċm�F				ErrCodeNo=1000+401
				DispMsg2Item= 30
				DispMsg3Item= 31
			
			end select
			
			'DispMsg1Relay=ON

		errcode = 0

		end if

		
		
		
	end if 'if errcode
 

