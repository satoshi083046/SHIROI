'Main
'===================================================================================================================
'
'<<<<<<<	Main���암	>>>>>>>>
'
'===================================================================================================================
'-------------------------------------------------------------------------------------------------------------------
'
'	�����@����
'
'  192.168.4.10	
'	+----[���a]-[�t�^�킹]- <����>---[�t�^���][���m][�o�L���[��]---[�ق���A]
'   |                                     		                  |
'	+---[����]--[B��]--[A��] - [���@] ----------------------------[�ق���B]
'
'-------------------------------------------------------------------------------------------------------------------
' �֎~����
'	�z��A�֎~�A�z��B�֎~�A�����֎~�A�Ȃ炵�֎~�A�t�^�킹�֎~�A�t�^��֎~�A
'
'-------------------------------------------------------------------------------------------------------------------
'�y�O�����H���z
'	�O����
'		����			DM_A�^���N�ݒ�l > 0
'		����			DM_A�^���N���Č��ݒl < DM_A�^���N�ݒ�l
'
'		���ăJ�E���g 	DM_�Z�Ѓ^���NA���Ċ���=DM_A�^���N���Č��ݒl - DM_A�z�Č��ݒl
'
'		�蓮�E�Z�Ѓ^���N�r�� and �Ė��� 	DM_A�^���N���Č��ݒl=0 DM_�Z�Ѓ^���NA���Ċ���=0
'
'	�����R���x�A�^�]
'
'		�����������ݒl>=���������ݒ�l
'			*���ъ�ɒ��΂���^�C�~���O
'		�z�ď����������ݒl>=�z�ď��������ݒ�l and  ldp(PB22_�����^�] and ��������AutoMode)  DM_A�z�Č��ݒl=0
'			*�z�ď��������F�z�ĉ\�Ȑ�򂳂ꂽ��
'
'		�z��			DM_�Z�Ѓ^���NA���Ċ���>0
'		�z�ďI��		DM_A�z�Đݒ�l=0 or DM_A�z�Č��ݒl>=DM_A�z�Đݒ�l or �Ė���
'
'		���Όx���܂ł̎c����>=���Όx���܂ł̎c�����ݒ�l
'
'		DM_�r�o�c��=0
'			*�����I���^�C�~���O(���т��ꂽ�������I�������^�C�~���O)
'
'-------------------------------------------------------------------------------------------------------------------
'�f�o�b�N���j�^�[
'
DM_�v�ʌ��ݒl.U=CNT_�v�ʌ��ݒl.U

DM_A�^���N�ݒ�l=DM_A�^���N�ݒ�l
DM_A�^���N���Č��ݒl=DM_A�^���N���Č��ݒl
DM_A�^���N���Č��ݒl�c��=DM_A�^���N�ݒ�l-DM_A�^���N���Č��ݒl
if DM_A�^���N���Č��ݒl�c��<0 then
	DM_A�^���N���Č��ݒl�c��=0
end if
DM_�Z�Ѓ^���NA���Ċ���=DM_�Z�Ѓ^���NA���Ċ���
DM_A�z�Đݒ�l=DM_A�^���N�ݒ�l+DM_A�^���N�␳�l 'DM_A�^���N�␳�l (�����l=5)
DM_A�z�Č��ݒl=DM_A�z�Č��ݒl
DM_A�z�Č��ݒl�c��=DM_A�z�Đݒ�l-DM_A�z�Č��ݒl
if DM_A�z�Č��ݒl�c��<0 then
	DM_A�z�Č��ݒl�c��=0
end if


	if DM_A�z�Č��ݒl=0 then
		�z�Č��ݒlA�O���t=0
	else if DM_A�z�Č��ݒl>=DM_A�^���N�ݒ�l then
		�z�Č��ݒlA�O���t=100
	else
		�z�Č��ݒlA�O���t=(DM_A�z�Č��ݒl*100)/ DM_A�^���N�ݒ�l
	end if


'
DM_B�^���N�ݒ�l=DM_B�^���N�ݒ�l
DM_B�^���N���Č��ݒl=DM_B�^���N���Č��ݒl
DM_B�^���N���Č��ݒl�c��=DM_B�^���N�ݒ�l-DM_B�^���N���Č��ݒl
if DM_B�^���N���Č��ݒl�c��<0 then
	DM_B�^���N���Č��ݒl�c��=0
end if
DM_�Z�Ѓ^���NB���Ċ���=DM_�Z�Ѓ^���NB���Ċ���
DM_B�z�Đݒ�l=DM_B�^���N�ݒ�l+DM_B�^���N�␳�l 'DM_B�^���N�␳�l (�����l=5)
DM_B�z�Č��ݒl=DM_B�z�Č��ݒl


	if DM_B�z�Č��ݒl=0 then
		�z�Č��ݒlB�O���t=0
	else if DM_B�z�Č��ݒl >= DM_B�^���N�ݒ�l then
		�z�Č��ݒlB�O���t=100
	else
		�z�Č��ݒlB�O���t= (DM_B�z�Č��ݒl*100) / DM_B�^���N�ݒ�l
	end if


DM_B�z�Č��ݒl�c��=DM_B�z�Đݒ�l-DM_B�z�Č��ݒl
if DM_B�z�Č��ݒl�c��<0 then
	DM_B�z�Č��ݒl�c��=0
end if

DM_�z�đ����ݒ�l=DM_A�^���N�ݒ�l+DM_B�^���N�ݒ�l
DM_�z�đ���=DM_A�z�Č��ݒl+DM_B�z�Č��ݒl
DM_�r�o�c��=DM_�z�đ���-DM_�r�o����
if DM_�r�o�c��<0 or (DM_�r�o�c��>=0 and pnlPB�r�o�c�����Z�b�g) then
	DM_�r�o����=DM_�z�đ���
	DM_�r�o�c��=0	
end if

	if DM_�r�o����=0 then
		���]�����ݒl�O���t=0
		���]���c���O���t=0
	else if DM_�r�o����>=DM_�z�đ��� then
		���]�����ݒl�O���t=100
		���]���c���O���t=0
	else
		���]�����ݒl�O���t=(DM_�r�o����*100) / DM_�z�đ���
		���]���c���O���t=100-((DM_�r�o����*100) / DM_�z�đ���)
	end if


�^�]������=�^�]������
�^�]��������=�^�]��������


���������ݒ�l=���������ݒ�l '(�����l=25) 
�����������ݒl=�����������ݒl
�����������ݒl�c��=���������ݒ�l-�����������ݒl
if �����������ݒl�c��<0 then
	�����������ݒl�c��=0
end if

�z�ď��������ݒ�l=�z�ď��������ݒ�l '(�����l=5)
�z�ď����������ݒl=�z�ď����������ݒl
�z�ď����������ݒl�c��=�z�ď��������ݒ�l-�z�ď����������ݒl
if �z�ď����������ݒl�c��<0 then
	�z�ď����������ݒl�c��=0
end if

���Όx���܂ł̎c�����ݒ�l=���Όx���܂ł̎c�����ݒ�l '(�����l=30)
���Όx���܂ł̎c����=���Όx���܂ł̎c����
���Όx���܂ł̎c�����c��=���Όx���܂ł̎c�����ݒ�l-���Όx���܂ł̎c����
if ���Όx���܂ł̎c�����c��<0 then
	���Όx���܂ł̎c�����c��=0
end if

�z�ďI���t���O=�z�ďI���t���O


'-------------------------------------------------------------------------------------------------------------------
'	<<< ����d�l  �t���[��B	>>> 
'-------------------------------------------------------------------------------------------------------------------
'
'����T�v
'�^�]�J�n�����~�܂ł̃t���[

'===================================================================================================================
'�y ���������� �z
'-------------------------------------------------------
if CR2008 then '�d��ON������������
	if PB34_���Z�b�g then

		�����������ݒl=0
		�z�ď����������ݒl=0
		DM_A�z�Č��ݒl=0
		DM_B�z�Č��ݒl=0
		DM_�r�o����=0
		
		���Όx���܂ł̎c����=0
		�󊘔�������=0
		���J�E���gA=0
		���J�E���gB=0
				
		�^�]������=OFF
		�z�đҋ@��=OFF
		�^�]��������=OFF
		
		������~=OFF
		IND_������~�\=OFF
		
		�C���^�[�o��������=OFF
	
	end if
	
end if

'-------------------------------------------------------
if ldp(�e�X�g�^�]) then '�e�X�g�^�]�����オ�� ��
	�Z�Ѓ^���NA���j�b�g����=OFF
	�Z�Ѓ^���NB���j�b�g����=OFF
	���^���NAutoMode=ON
	���^���NAutoRun=ON
	�������֎~=ON

else if ldf(�e�X�g�^�]) then  '�e�X�g�^�]������ ��
		���^���NAutoMode=OFF
		���^���NAutoRun=OFF
		�������֎~=OFF
end if

'-------------------------------------------------------
if ldp(���ы@�_�Ύ��s�m�F�y�ρz) then
	IND_���ђ�=ON
end if

if ldp(���ы@���Όx���y�ρz) then
	IND_���ђ�=OFF
end if


'-------------------------------------------------------
'�e�H������ 
if �e�X�g�^�] then
	������~=OFF
	IND_������~�\=OFF
end if

if not(�e�X�g�^�]) then

'--�^�]������
if �^�]������ then
	if Main�菇������ then
		Main�菇������=OFF
		
		tmsg�^�]�����J�n�m�F=OFF
		tmsg�^�]�����J�n�m�F����=OFF
		
		tmsg�^�]��������=OFF
		tmsg�^�]������������=OFF
		
	end if

	IND_�z�ď���=ON
	IND_�z�Ē�=OFF
	IND_���ђ�=OFF
	IND_���ъ���=OFF
	IND_��~�ҋ@=OFF

	
	�Z�Ѓ^���NA���j�b�g����=OFF
	�Z�Ѓ^���NB���j�b�g����=OFF
	
	if ���ы@�_�Ύ��s�m�F�y�ρz then

		tmsg�^�]�����J�n�m�F=OFF
		tmsg�^�]�����J�n�m�F����=ON		
		'���^���N=ON

		if ��������AutoMode and ��������AutoRun then
			���^���NAutoMode=ON
			���^���NAutoRun=ON
		end if

		tmsg���ы@�_�Ύ��s�x��=OFF


		if �z�ď����������ݒl>=�z�ď��������ݒ�l or �������֎~ then '�������𐆔ы@�ɔ����ς�
			�^�]������=OFF
			�z�đҋ@��=ON
			�^�]��������=OFF

			tmsg�^�]��������=ON
			tmsg�^�]������������=OFF
			
			MainStatusMsg=#110
		
		end if
		

	else if �^�]�����J�n�m�F�y�ρz then '���^���NAutoRun�ς�

		'���^���N=ON
		tmsg�^�]�����J�n�m�F=OFF
		tmsg�^�]�����J�n�m�F����=ON
		
		if ��������AutoMode and ��������AutoRun then
			���^���NAutoMode=ON
			���^���NAutoRun=ON
		end if
	
		if �����������ݒl>=���������ݒ�l then
			tmsg���ы@�_�Ύ��s�x��=ON
		end if
		
		if pnlPBOK then
			���ы@�_�Ύ��s�m�F�y�ρz=ON
			tmsg���ы@�_�Ύ��s�x��=OFF

			�z�ď����������ݒl=0
		end if				

	else
	
		���C��TP_�ؑփy�[�W�m��=22
		tmsg�^�]�����J�n�m�F=ON
		tmsg�^�]�����J�n�m�F����=OFF


		if ldp(PB22_�����^�] and ��������AutoMode) and PB23_������~  then 'and ��������AutoRun then

			'���^���N=ON
			�^�]�����J�n�m�F�y�ρz=ON
			tmsg�^�]�����J�n�m�F=OFF
			tmsg�^�]�����J�n�m�F����=ON
			
			���^���NAutoMode=ON
			���^���NAutoRun=ON

		end if
	
	end if
	
	

'--�z�đҋ@��
else if �z�đҋ@�� then

		�^�]������=OFF
		�z�đҋ@��=ON
		�^�]��������=OFF
	
		if ��������AutoMode then
			tmsg�^�]��������=ON
			tmsg�^�]������������=OFF
		else 
			tmsg�^�]��������=OFF
			tmsg�^�]������������=ON
		end if	
		
		if ��������AutoMode and ��������AutoRun then
			���^���NAutoMode=ON
			���^���NAutoRun=ON
		end if

		IND_�z�Ē�=CR2006

		if ��������AutoMode and (ldp(pnlPBOK) or ldp(pnlPB�z�Ē�)) then 'and ��������AutoRun then

			�^�]������=OFF
			�z�đҋ@��=OFF
			�^�]��������=ON			
			
			���ы@���Όx���y�ρz=OFF
			���ъ�����~�y�ρz=OFF
			�z�ďI���t���O=OFF

			'-------------------------------------------------------
			'�f�[�^�N���A
			'-------------------------------------------------------			
			DM_A�z�Č��ݒl=0
			DM_B�z�Č��ݒl=0
			DM_�r�o����=0
			
			'tmsgxxxx=OFF
			tmsg�^�]�����J�n�m�F=OFF
			tmsg�^�]�����J�n�m�F����=ON
			
			tmsg���ы@�_�Ύ��s�x��=OFF

			tmsg�^�]��������=OFF
			tmsg�^�]������������=ON

			tmsg���ы@���Όx���\��=OFF
			tmsg���ы@���Όx������=ON
			
			tmsg���ъ����\��=OFF '���ъ����ʒm
			tmsg���ъ�������=ON '���ъ����ʒm

			'-------------------------------------------------------
			StageDevice37=0 '�����]�ʒu(���]�ʒu�j
			StageDevice38=0 '���t�g�ʒu
			StageDevice0=0 '�y�������z �����R���x�AA MC6
			StageDevice1=0 '�y�Z�Ѓ^���NA�z �����R���x�AA MC6-MC7
			StageDevice2=0 '�y�Z�Ѓ^���NB�z �����R���x�AA MC7
			StageDevice3=0 '�y�����z �����R���x�AA MC7�|MC8
			StageDevice4=0 '�y���t�g�ʒu�z �����R���x�AA MC8�|MC9
			StageDevice5=0 '�y�ҋ@�ʒu1�z �����R���x�AB MC9�|MC12
			StageDevice6=0 '�y�ҋ@�ʒu2�z �����R���x�AB MC12�|MC13
			StageDevice7=0 '�y���t�g�ʒu�z �����R���x�AB MC13�|MC16
			StageDevice8=0 '�y�Ȃ炵�ʒu�z �����R���x�AC MC16�|MC14
			StageDevice9=0 '�y�t�^�킹�ʒu�z �����R���x�AC MC14�|MC15
			'-------------------------------------------------------

			�^�]������=OFF
		end if



'--�^�]�������� (�z�ĉ^�]�j
else if �^�]�������� then

	�^�]����������=OFF
	Main�菇������=OFF
	
	if ��������AutoMode and ��������AutoRun then
		���^���NAutoMode=ON
		���^���NAutoRun=ON
	end if
	
	if not(�^�]������) then '�^�]����������<�������e>���o�^
		'<�������e>
		�^�]������=ON
		
		IND_�z�ď���=OFF
		IND_�z�Ē�=OFF
		IND_���ђ�=ON
		IND_���ъ���=OFF
		IND_��~�ҋ@=OFF
		
		�Z�Ѓ^���NA���j�b�g����=ON
		�Z�Ѓ^���NB���j�b�g����=ON
	end if

	if �A���t�@���ă��[�h then
		�Z�Ѓ^���NA���j�b�g����=OFF
		�Z�Ѓ^���NB���j�b�g����=OFF
		
		if �z�ďI���t���O or (DM_�z�đ���>DM_�z�đ����ݒ�l or DM_�z�đ���=DM_�z�đ����ݒ�l) then
			�z�ďI���t���O=ON
			IND_�z�Ē�=OFF		
		else
			�z�ďI���t���O=OFF
			IND_�z�Ē�=ON		
		end if
	
	else
		if �z�ďI���t���O or (not(�Z�Ѓ^���NA���j�b�g����) and not(�Z�Ѓ^���NB���j�b�g����)) then
			IND_�z�Ē�=OFF
		else
			IND_�z�Ē�=ON
		end if
		
		'-- A�z�Ċ��� and B�z�Ċ���
		if (DM_A�^���N�ݒ�l=0 or �Z�Ѓ^���NA�Ė���) and  (DM_B�^���N�ݒ�l=0 or �Z�Ѓ^���NB�Ė���) then
			�z�ďI���t���O=ON
		else 
			�z�ďI���t���O=OFF
		end if
	end if
	
	if IND_�z�Ē� then
		if ldp(�Z�Ѓ^���NA�Ė���) then
			pnlPB�����Ė���A=ON
		else if ldp(�Z�Ѓ^���NB�Ė���) then
			pnlPB�����Ė���B=ON
		end if
		
	end if
	
		
	'-- �O���[�o����ʕ\��
	if tmsg�z�Ċ����\��=ON then
		if pnlPB�߂� then
				�z�ďI���t���O=OFF
				tmsg�z�Ċ����\��=OFF '�z�Ċ����\��
				tmsg�z�Ċ�������=ON '�z�Ċ����\��
		end if
	end if
		
	if �z�ďI���t���O then
		
		if not(�z�Ċ����\���y�ρz) and not(���ы@���Όx���y�ρz) and not(���ъ�����~�y�ρz)  then

				tmsg�z�Ċ����\��=ON '�z�Ċ����\��
				tmsg�z�Ċ�������=OFF '�z�Ċ����\��

				if pnlPBOK or ���Όx���܂ł̎c����>=���Όx���܂ł̎c�����ݒ�l then
				
					if pnlPBOK then
						���Όx���܂ł̎c����=0
					end if
					tmsg�z�Ċ����\��=OFF '�z�Ċ����\��
					tmsg�z�Ċ�������=ON '�z�Ċ����\��
					�z�Ċ����\���y�ρz=ON
				
				end if
	
		else if �z�Ċ����\���y�ρz and not(���ы@���Όx���y�ρz) and not(���ъ�����~�y�ρz)  then
			�C���^�[�o��������=OFF
		
			if ���Όx���܂ł̎c����>=���Όx���܂ł̎c�����ݒ�l or DM_�r�o�c��<=0 or tmsg���ы@���Όx���\�� then
	
					MainStatusMsg=#121 '��~�������B���ы@���Ή\�ł��B
					tmsg���ы@���Όx���\��=ON
					tmsg���ы@���Όx������=OFF

					if ldp(pnlPBOK) or DM_�r�o�c��<=0 then
						tmsg���ы@���Όx���\��=OFF
						tmsg���ы@���Όx������=ON

						DM_EndCnt=6
						������~=OFF
						IND_������~�\=OFF

						���ы@���Όx���y�ρz=ON
					end if
					
			end if
					
			
		else if  �z�Ċ����\���y�ρz and ���ы@���Όx���y�ρz and not(���ъ�����~�y�ρz) then
		
			if DM_�r�o�c��<=0 or tmsg���ъ����\�� then

					MainStatusMsg=#120 '��~������		
					tmsg���ъ����\��=ON '���ъ����ʒm
					tmsg���ъ�������=OFF '���ъ����ʒm

					IND_���ъ���=ON
					IND_���ђ�=OFF

					IND_��~�ҋ@=CR2006
					
					

					if not(PB23_������~) or not(PB35_��~) or not(PB17_������~) or ������~ then
						tmsg���ъ����\��=OFF '���ъ����ʒm
						tmsg���ъ�������=ON '���ъ����ʒm

						���ъ�����~�y�ρz=ON
					end if
			else
				DM_EndCnt=6
				������~=OFF
				IND_������~�\=OFF
			end if
			

			select case DM_EndCnt
			case 0
				IND_EndCnt1=OFF
				IND_EndCnt2=OFF
				IND_EndCnt3=OFF
				IND_EndCnt4=OFF
				IND_EndCnt5=OFF
				IND_EndCnt6=OFF
				IND_EndCnt7=OFF
				IND_EndCnt8=OFF
				
				if ������~�ݒ� then
					������~=ON
				else 
					������~=OFF
				end if
				IND_������~�\=ON
				
			case 1
				IND_EndCnt1=ON
				IND_EndCnt2=OFF
				IND_EndCnt3=OFF
				IND_EndCnt4=OFF
				IND_EndCnt5=OFF
				IND_EndCnt6=OFF
				IND_EndCnt7=OFF
				IND_EndCnt8=OFF
			case 2
				IND_EndCnt1=ON
				IND_EndCnt2=ON
				IND_EndCnt3=OFF
				IND_EndCnt4=OFF
				IND_EndCnt5=OFF
				IND_EndCnt6=OFF
				IND_EndCnt7=OFF
				IND_EndCnt8=OFF
			case 3
				IND_EndCnt1=ON
				IND_EndCnt2=ON
				IND_EndCnt3=ON
				IND_EndCnt4=OFF
				IND_EndCnt5=OFF
				IND_EndCnt6=OFF
				IND_EndCnt7=OFF
				IND_EndCnt8=OFF
			case 4
				IND_EndCnt1=ON
				IND_EndCnt2=ON
				IND_EndCnt3=ON
				IND_EndCnt4=ON
				IND_EndCnt5=OFF
				IND_EndCnt6=OFF
				IND_EndCnt7=OFF
				IND_EndCnt8=OFF
			case 5
				IND_EndCnt1=ON
				IND_EndCnt2=ON
				IND_EndCnt3=ON
				IND_EndCnt4=ON
				IND_EndCnt5=ON
				IND_EndCnt6=OFF
				IND_EndCnt7=OFF
				IND_EndCnt8=OFF
			case 6
				IND_EndCnt1=ON
				IND_EndCnt2=ON
				IND_EndCnt3=ON
				IND_EndCnt4=ON
				IND_EndCnt5=ON
				IND_EndCnt6=ON
				IND_EndCnt7=OFF
				IND_EndCnt8=OFF
			case 7
				IND_EndCnt1=ON
				IND_EndCnt2=ON
				IND_EndCnt3=ON
				IND_EndCnt4=ON
				IND_EndCnt5=ON
				IND_EndCnt6=ON
				IND_EndCnt7=ON
				IND_EndCnt8=OFF
			case 8
				IND_EndCnt1=ON
				IND_EndCnt2=ON
				IND_EndCnt3=ON
				IND_EndCnt4=ON
				IND_EndCnt5=ON
				IND_EndCnt6=ON
				IND_EndCnt7=ON
				IND_EndCnt8=ON
			end select
			

			if IND_���ъ���=ON then
				if	�ق����@A���j�b�gstep=1 and �ق����@A���j�b�g���� then
					���]�ق����@A�֎~=ON
				end if
				if	�ق����@B���j�b�gstep=1 and �ق����@B���j�b�g���� then
					���]�ق����@B�֎~=ON
				end if
			end if
			
		else if  �z�Ċ����\���y�ρz and ���ы@���Όx���y�ρz and ���ъ�����~�y�ρz then
		
				tmsg���ъ����\��=OFF '���ъ����ʒm
				tmsg���ъ�������=ON  '���ъ����ʒm					

				IND_���ъ���=OFF
				IND_��~�ҋ@=OFF
				�^�]��������=OFF
				
				pnlPB�����Ė���A=OFF
				pnlPB�����Ė���B=OFF
				
	
		end if
	
	else

		�z�Ċ����\���y�ρz=OFF
		���ы@���Όx���y�ρz=OFF
		���ъ�����~�y�ρz=OFF

	end if
	
	
else '�^�]����=OFF �^�]��������=OFF
	if not(PB23_������~) then

		���C��TP_�ؑփy�[�W�m��=22

		'tmsgxxxx=OFF
		tmsg�^�]�����J�n�m�F=OFF
		tmsg�^�]�����J�n�m�F����=OFF
		
		tmsg�^�]��������=OFF
		tmsg�^�]������������=OFF
		
		tmsg���ы@�_�Ύ��s�x��=OFF
		
		tmsg���ы@���Όx���\��=OFF
		tmsg���ы@���Όx������=OFF

		tmsg���ъ����\��=OFF
		tmsg���ъ�������=OFF

	else 

	IND_�z�ď���=OFF
	IND_�z�Ē�=OFF
	IND_���ђ�=OFF
	IND_���ъ���=OFF
	IND_��~�ҋ@=OFF
			
	�^�]������=OFF
	�z�đҋ@��=OFF
	�^�]��������=OFF
	
	������~=OFF
	IND_������~�\=OFF



		if ���C��TP_�ؑփy�[�W�m��=15 then

			if ���C�ݔ��m�F�y�ρz and �Z�Ѓ^���N�ē����m�F�y�ρz and �Z�Ѓ^���N�ē����m�F�y�ρz and �r�����m�F�y�ρz then
				if pnlPBOK then
				
					�^�]������=ON
					�z�đҋ@��=OFF
					�^�]��������=OFF
					���C��TP_�ؑփy�[�W�m��15�y�ρz=ON
					���C�ݔ��m�F�y�ρz=OFF
					�Z�Ѓ^���N�ē����m�F�y�ρz=OFF
					�Z�Ѓ^���N�ē����m�F�y�ρz=OFF
					�r�����m�F�y�ρz=OFF
					
	
				end if
			end if

		else if ldp(PB22_�����^�]) and PB23_������~ and ��������AutoMode then
			
			'�^�]�����̂��߂̏����ݒ�
			���C��TP_�ؑփy�[�W�m��=15
			
			'xxx�y�ρz=OFF
			���C��TP_�ؑփy�[�W�m��15�y�ρz=OFF
			���C�ݔ��m�F�y�ρz=OFF
			�Z�Ѓ^���N�ē����m�F�y�ρz=OFF
			�Z�Ѓ^���N�ē����m�F�y�ρz=OFF
			�r�����m�F�y�ρz=OFF					

			�^�]�����J�n�m�F�y�ρz=OFF
			���ы@�_�Ύ��s�m�F�y�ρz=OFF
			�z�ďI���t���O=OFF
			�z�Ċ����\���y�ρz=OFF

			shiftreg���t�^����0=0
			shiftreg���t�^����1=0
			shiftreg���t�^����2=0
			shiftreg���t�^����3=0
			shiftreg���t�^����4=0
			shiftreg���t�^����5=0
			
		else		
			if not(Main�菇������) then
				
				���^���NAutoMode=OFF
				���^���NAutoRun=OFF
				
				Main�菇������=ON
			end if

			if not(�^�]����������) then
				
				���C��TP_�ؑփy�[�W�m��=22
				���C��TP_�ؑփy�[�W�m��15�y�ρz=OFF
				�����������ݒl=0
				�z�ď����������ݒl=0
				DM_A�z�Č��ݒl=0
				DM_B�z�Č��ݒl=0
				DM_�r�o����=0

				���Όx���܂ł̎c����=0
				��������=0
				�󊘔�������=0
				���J�E���gA=0
				���J�E���gB=0
				
				�z�ďI���t���O=OFF
			
				�^�]����������=ON

			end if
			
			�����������ݒl=0
			�z�ď����������ݒl=0
			DM_A�z�Č��ݒl=0
			DM_B�z�Č��ݒl=0
			DM_�r�o����=0
			
			���Όx���܂ł̎c����=0
			�󊘔�������=0
			���J�E���gA=0
			���J�E���gB=0
			

		end if
		
	end if
	
end if

end if

'===================================================================================================================
'�\���M����ON�̂Ƃ��A�����M�������ׂ�OFF�ɂ���B
tmr(t�u�U�[�x��,tim_t�u�U�[�x��,#20)
�u�U�[�x��=t�u�U�[�x�� and not(tim_t�u�U�[�x��.B) 

if tmsg�^�]�����J�n�m�F or tmsg���ы@�_�Ύ��s�x�� or tmsg�^�]�������� or tmsg�z�Ċ����\�� or tmsg���ы@���Όx���\�� or tmsg���ъ����\�� then

	t�u�U�[�x��=ON
	tmsg�^�]�����J�n�m�F����=OFF
	tmsg�^�]������������=OFF
	tmsg���ъ�������=OFF
	tmsg���ы@���Όx������=OFF
	tmsg�z�Ċ�������=OFF
else
	t�u�U�[�x��=OFF
end if

'===================================================================================================================
'msg�M��(2sec)�m��o��

if (20<=���C��TP_�\�����y�[�WNo and ���C��TP_�\�����y�[�WNo<=29) and (20<=�T�uTP_�\�����y�[�WNo and �T�uTP_�\�����y�[�WNo<=29) and (20<=�ނ炵TP_�\�����y�[�WNo and �ނ炵TP_�\�����y�[�WNo<=29) then

	tmr(tmsg�^�]�����J�n�m�F,tim_tmsg�^�]�����J�n�m�F,20)
	msg�^�]�����J�n�m�F=tmsg�^�]�����J�n�m�F and not(tim_tmsg�^�]�����J�n�m�F.B)
	tmr(tmsg�^�]�����J�n�m�F����,tim_tmsg�^�]�����J�n�m�F����,20)
	msg�^�]�����J�n�m�F����=tmsg�^�]�����J�n�m�F���� and not(tim_tmsg�^�]�����J�n�m�F����.B)

	tmr(tmsg�^�]��������,tim_tmsg�^�]��������,20)
	msg�^�]��������=tmsg�^�]�������� and not(tim_tmsg�^�]��������.B)
	tmr(tmsg�^�]������������,tim_tmsg�^�]������������,20)
	msg�^�]������������=tmsg�^�]������������ and not(tim_tmsg�^�]������������.B)

	tmr(tmsg���ы@���Όx���\��,tim_tmsg���ы@���Όx���\��,20)
	msg���ы@���Όx���\��=tmsg���ы@���Όx���\�� and not(tim_tmsg���ы@���Όx���\��.B)
	tmr(tmsg���ы@���Όx������,tim_tmsg���ы@���Όx������,20)
	msg���ы@���Όx������=tmsg���ы@���Όx������ and not(tim_tmsg���ы@���Όx������.B) 

	tmr(tmsg���ы@�_�Ύ��s�x��,tim_tmsg���ы@�_�Ύ��s�x��,20)
	msg���ы@�_�Ύ��s�x��=tmsg���ы@�_�Ύ��s�x�� and not(tim_tmsg���ы@�_�Ύ��s�x��.B)
	'---
	tmr(tmsg�z�Ċ����\��,tim_tmsg�z�Ċ����\��,20)
	msg�z�Ċ����\��=tmsg�z�Ċ����\�� and not(tim_tmsg�z�Ċ����\��.B)
	tmr(tmsg�z�Ċ�������,tim_tmsg�z�Ċ�������,20)
	msg�z�Ċ�������=tmsg�z�Ċ������� and not(tim_tmsg�z�Ċ�������.B)
	'---
	tmr(tmsg���ъ����\��,tim_tmsg���ъ����\��,20)
	msg���ъ����\��=tmsg���ъ����\�� and not(tim_tmsg���ъ����\��.B)
	tmr(tmsg���ъ�������,tim_tmsg���ъ�������,20)
	msg���ъ�������=tmsg���ъ������� and not(tim_tmsg���ъ�������.B)

else 
	msg�^�]�����J�n�m�F=OFF
	msg�^�]�����J�n�m�F����=ON
	
	msg���ы@�_�Ύ��s�x��=OFF
	
	msg�^�]��������=OFF
	msg�^�]������������=ON
	
	msg�z�Ċ����\��=OFF	
	msg�z�Ċ�������=ON
	
	msg���ъ����\��=OFF
	msg���ъ�������=ON
	
	msg���ы@���Όx���\��=OFF
	msg���ы@���Όx������=ON

end if

tmr(msgFleshCycl,#40)
if ldp(msgFleshCycl.B) then
	res(msgFleshCycl)

	res(tim_tmsg�^�]�����J�n�m�F)
	res(tim_tmsg�^�]�����J�n�m�F����)	
	res(tim_tmsg�^�]��������)
	res(tim_tmsg�^�]������������)
	res(tim_tmsg���ъ����\��)
	res(tim_tmsg���ъ�������)
	res(tim_tmsg���ы@���Όx���\��)
	res(tim_tmsg���ы@���Όx������)
	res(tim_tmsg���ы@�_�Ύ��s�x��)
	res(tim_tmsg�z�Ċ����\��)
	res(tim_tmsg�z�Ċ�������)

end if

'===================================================================================================================

'===================================================================================================================
'	���C������{�b�N�X					�T�u�{�b�N�X				�ނ炵����{�b�N�X
'-------------------------------------------------------------------------------------------------------------------
'	PL9_�^�]��							PBL11_�^�]��				PBL14_�ނ炵�^�]��
'	PL10_�ُ�							PBL12_�ُ�					PL7_�ނ炵�@�ُ�
'
'	PB22_�����^�]	PBL22_�����^�]		
'	PB23_������~						PB35_��~					PB17_������~
'
'	PB34_���Z�b�g						PB24_���Z�b�g				PB6_���Z�b�g
'
'	SSW3_�蓮���[�h													SEL2_1_�^�]�؊��i�P���j
'	SSW3_�������[�h													SEL2_2_�^�]�؊��i�A���j
'
'																	PB18_�G�X�P�[�v
'===================================================================================================================
'

	PTL1_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL2_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL3_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL4_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL5_�p�g���C�g��=�p�g���C�g�� and CR2006
	'
	PTL1_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL2_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL3_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL4_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL5_�p�g���C�g��=�p�g���C�g�� and CR2006
	'
	PTL1_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL2_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL3_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL4_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL5_�p�g���C�g��=�p�g���C�g�� and CR2006

if 1 then
	PTL1_�p�g���C�g�u�U�[=alm�a�،x�� or (�u�U�[�x�� and CR2006) 
	PTL2_�p�g���C�g�u�U�[=alm�a�،x�� or (�u�U�[�x�� and CR2006)
	PTL3_�p�g���C�g�u�U�[=alm�a�،x�� or (�u�U�[�x�� and CR2006)
	PTL4_�p�g���C�g�u�U�[=alm�a�،x�� or (�u�U�[�x�� and CR2006)
	PTL5_�p�g���C�g�u�U�[=alm�a�،x�� or (�u�U�[�x�� and CR2006)
end if

	if ��������ErrStep<>0 or ��������EmgStep<>0 then
		�p�g���C�g��=ON
		�p�g���C�g��=OFF
		�p�g���C�g��=OFF	
	else if OtherErrStep<>0 or �R���x�A�ꎞ��~�� then
		�p�g���C�g��=OFF
		�p�g���C�g��=ON
		�p�g���C�g��=OFF
	else if ��������AutoRun then
		�p�g���C�g��=OFF
		�p�g���C�g��=OFF
		�p�g���C�g��=ON
	else
		�p�g���C�g��=OFF
		�p�g���C�g��=OFF
		�p�g���C�g��=OFF	
	end if	
	

' PL�C���W�P�[�^

	PBL22_�����^�]=�^�]�������� and ��������AutoRun
	
	'--------------------------------
	if ��������AutoRun then
		PL9_�^�]��=ON
		PBL11_�^�]��=ON
		PBL14_�ނ炵�^�]��=ON
	else
		if OtherStep<>0 then
			if CR2006 then
				PL9_�^�]��=ON
				PBL11_�^�]��=ON
				PBL14_�ނ炵�^�]��=ON
			else
				PL9_�^�]��=OFF
				PBL11_�^�]��=OFF
				PBL14_�ނ炵�^�]��=OFF

			end if
		else
			PL9_�^�]��=OFF
			PBL11_�^�]��=OFF
			PBL14_�ނ炵�^�]��=OFF
		end if
		
	end if

	'--------------------------------
	if ��������ErrStep<>0 or OtherEmgStep<>0 or OtherErrStep<>0  or �R���x�A�ꎞ��~�� then

		if CR2006 then
			PL10_�ُ�=ON
			PBL12_�ُ�=ON
			PL7_�ނ炵�@�ُ�=ON
		else
			PL10_�ُ�=OFF
			PBL12_�ُ�=OFF
			PL7_�ނ炵�@�ُ�=OFF
		end if

	else

		PL10_�ُ�=OFF
		PBL12_�ُ�=OFF
		PL7_�ނ炵�@�ُ�=OFF

	end if
	'--------------------------------
'===================================================================================================================
'�G�X�P�[�v
	if ldp(PB18_�G�X�P�[�v) then
		if �G�X�P�[�v�� then
			PBL18_�G�X�P�[�v��=OFF
			�G�X�P�[�v��=OFF
		else
			PBL18_�G�X�P�[�v��=ON
			�G�X�P�[�v��=ON

			if not(�����R���x�ADAutoRun) and �����R���x�ADstep=0 and MC19_�������[�^=OFF then
				if PH22_�����m then
					mSV41_���t�g=ON
				end if
			end if
		
		end if
	end if
		
'===================================================================================================================
'���^���N���� �\��^�]���[�h
if ���^���N�����^�]���[�h or (���^���N�\��^�]���[�h and ldp(���^���NONTIME)) then
	���^���NAutoMode=ON
	���^���NAutoRun=ON
end if


'===================================================================================================================
'����~�t���O
	tmr(ESPB5_����~,ESPB5_����~tim,2)
	tmr(not(ESPB1_����~),ESPB1_����~tim,2)
	tmr(not(ESPB2_����~),ESPB2_����~tim,2)
	tmr(not(ESPB3_����~IN),ESPB3_����~INtim,2)
	tmr(not(ESPB4_����~IN),ESPB4_����~INtim,2)
	tmr(not(PB26_�R���x�A��~),PB26_�R���x�A��~tim,2)
	tmr(not(PB27_�R���x�A��~),PB27_�R���x�A��~tim,2)
	tmr(not(PB28_�R���x�A��~),PB28_�R���x�A��~tim,2)
	tmr(not(PB29_�R���x�A��~),PB29_�R���x�A��~tim,2)
	
	PB����~= not(ESPB5_����~tim or ESPB1_����~tim or ESPB2_����~tim or ESPB3_����~INtim or  ESPB4_����~INtim or PB26_�R���x�A��~tim or PB27_�R���x�A��~tim or PB28_�R���x�A��~tim or PB29_�R���x�A��~tim)
	ESPBL1_����~ =not(PB����~) and CR2006
	EmgFlg=not(PB����~) or EmgFlg
	if not(PB����~)  then
		if ESPB5_����~ then '���ċ@
			almESPB5_����~=ON
		else if not(ESPB1_����~) then '���C�������
			almESPB1_����~=ON
		else if not(ESPB2_����~) then '�T�u�����
			almESPB2_����~=ON
		else if not(ESPB3_����~IN) then '�ނ炵�����
			almESPB3_����~IN=ON
		else if not(ESPB4_����~IN) then  '�ނ炵�w��
			almESPB4_����~IN=ON
		else if not(PB26_�R���x�A��~) then
			almPB26_�R���x�A��~=ON
		else if not(PB27_�R���x�A��~) then
			almPB27_�R���x�A��~=ON
		else if not(PB28_�R���x�A��~) then
			almPB28_�R���x�A��~=ON 
		else if not(PB29_�R���x�A��~) then
			almPB29_�R���x�A��~=ON
		end if
			��������EmgStep=1
	end if
	
'���Z�b�g�t���O

	ResetFlg=PB34_���Z�b�g or PB24_���Z�b�g or PB6_���Z�b�g

'===================================================================================================================
'�X�e�[�W�V�O�i�� 
'===================================================================================================================
OtherOrgErr= �Z�Ѓ^���NA���j�b�gOrgErr
OtherOrgErr= OtherOrgErr or �Z�Ѓ^���NB���j�b�gOrgErr
OtherOrgErr= OtherOrgErr or �v�����j�b�gOrgErr
OtherOrgErr= OtherOrgErr or �Ȃ炵���uOrgErr
OtherOrgErr= OtherOrgErr or �W�킹���j�b�gOrgErr
OtherOrgErr= OtherOrgErr or �W��胆�j�b�gOrgErr
OtherOrgErr= OtherOrgErr or ���͂񌟒mOrgErr
OtherOrgErr= OtherOrgErr or �o�L���[�����j�b�gOrgErr
OtherOrgErr= OtherOrgErr or �ق����@A���j�b�gOrgErr
OtherOrgErr= OtherOrgErr or �ق����@B���j�b�gOrgErr
OtherOrgErr= OtherOrgErr or �����R���x�AAOrgErr
OtherOrgErr= OtherOrgErr or �����R���x�ABOrgErr
OtherOrgErr= OtherOrgErr or �����R���x�ACOrgErr
OtherOrgErr= OtherOrgErr or ������R���x�AOrgErr
OtherOrgErr= OtherOrgErr or �ނ炵�@������R���x�AOrgErr
OtherOrgErr= OtherOrgErr or �����R���x�ADOrgErr
OtherOrgErr= OtherOrgErr or �����R���x�AEOrgErr
OtherOrgErr= OtherOrgErr or �����R���x�AFOrgErr
OtherOrgErr= OtherOrgErr or ���������t�gOrgErr
OtherOrgErr= OtherOrgErr or ����������OrgErr
OtherOrgErr= OtherOrgErr or ��򃆃j�b�gOrgErr
'OtherOrgErr= OtherOrgErr or ���^���NOrgErr
OtherOrgErr= OtherOrgErr or ���R���x�A����OrgErr
OtherOrgErr= OtherOrgErr or ���o������OrgErr
OtherOrgErr= OtherOrgErr or ���t�^���~���uBOrgErr
OtherOrgErr= OtherOrgErr or �ނ炵�o��OrgErr

'===================================================================================================================
OtherErr= �Z�Ѓ^���NA���j�b�gErr
OtherErr= OtherErr or �Z�Ѓ^���NB���j�b�gErr
OtherErr= OtherErr or �v�����j�b�gErr
OtherErr= OtherErr or �Ȃ炵���uErr
OtherErr= OtherErr or �W�킹���j�b�gErr
OtherErr= OtherErr or �W��胆�j�b�gErr
OtherErr= OtherErr or ���͂񌟒mErr
OtherErr= OtherErr or �o�L���[�����j�b�gErr
OtherErr= OtherErr or �ق����@A���j�b�gErr
OtherErr= OtherErr or �ق����@B���j�b�gErr
OtherErr= OtherErr or �����R���x�AAErr
OtherErr= OtherErr or �����R���x�ABErr
OtherErr= OtherErr or �����R���x�ACErr
OtherErr= OtherErr or ������R���x�AErr
OtherErr= OtherErr or �ނ炵�@������R���x�AErr
OtherErr= OtherErr or �����R���x�ADErr
OtherErr= OtherErr or �����R���x�AEErr
OtherErr= OtherErr or �����R���x�AFErr
OtherErr= OtherErr or ���������t�gErr
OtherErr= OtherErr or ����������Err
OtherErr= OtherErr or ��򃆃j�b�gErr
OtherErr= OtherErr or ���^���NErr
OtherErr= OtherErr or ���R���x�A����Err
OtherErr= OtherErr or ���o������Err
OtherErr= OtherErr or ���t�^���~���uBErr
'==================================================================================================================
OtherEmg=�Z�Ѓ^���NA���j�b�gEmg
OtherEmg=OtherEmg or �Z�Ѓ^���NB���j�b�gEmg
OtherEmg=OtherEmg or �v�����j�b�gEmg
OtherEmg=OtherEmg or �Ȃ炵���uEmg
OtherEmg=OtherEmg or �W�킹���j�b�gEmg
OtherEmg=OtherEmg or �W��胆�j�b�gEmg
OtherEmg=OtherEmg or ���͂񌟒mEmg
OtherEmg=OtherEmg or �o�L���[�����j�b�gEmg
OtherEmg=OtherEmg or �ق����@A���j�b�gEmg
OtherEmg=OtherEmg or �ق����@B���j�b�gEmg
OtherEmg=OtherEmg or �����R���x�AAEmg
OtherEmg=OtherEmg or �����R���x�ABEmg
OtherEmg=OtherEmg or �����R���x�ACEmg
OtherEmg=OtherEmg or ������R���x�AEmg
OtherEmg=OtherEmg or �ނ炵�@������R���x�AEmg
OtherEmg=OtherEmg or �����R���x�ADEmg
OtherEmg=OtherEmg or �����R���x�AEEmg
OtherEmg=OtherEmg or �����R���x�AFEmg
OtherEmg=OtherEmg or ���������t�gEmg
OtherEmg=OtherEmg or ����������Emg
OtherEmg=OtherEmg or ��򃆃j�b�gEmg
'OtherEmg=OtherEmg or ���^���NEmg
OtherEmg=OtherEmg or ���R���x�A����Emg
OtherEmg=OtherEmg or ���o������Emg
OtherEmg=OtherEmg or ���t�^���~���uBEmg
'===================================================================================================================
OtherOrg=�Z�Ѓ^���NA���j�b�gOrg
OtherOrg= OtherOrg and �Z�Ѓ^���NB���j�b�gOrg
OtherOrg= OtherOrg and �v�����j�b�gOrg
OtherOrg= OtherOrg and �Ȃ炵���uOrg
OtherOrg= OtherOrg and �W�킹���j�b�gOrg
OtherOrg= OtherOrg and �W��胆�j�b�gOrg
OtherOrg= OtherOrg and ���͂񌟒mOrg
OtherOrg= OtherOrg and �o�L���[�����j�b�gOrg
OtherOrg= OtherOrg and �ق����@A���j�b�gOrg
OtherOrg= OtherOrg and �ق����@B���j�b�gOrg
OtherOrg= OtherOrg and �����R���x�AAOrg
OtherOrg= OtherOrg and �����R���x�ABOrg
OtherOrg= OtherOrg and �����R���x�ACOrg
OtherOrg= OtherOrg and ������R���x�AOrg
OtherOrg= OtherOrg and �ނ炵�@������R���x�AOrg
OtherOrg= OtherOrg and �����R���x�ADOrg
OtherOrg= OtherOrg and �����R���x�AEOrg
OtherOrg= OtherOrg and �����R���x�AFOrg
OtherOrg= OtherOrg and ���������t�gOrg
OtherOrg= OtherOrg and ����������Org
OtherOrg= OtherOrg and ��򃆃j�b�gOrg
'OtherOrg= OtherOrg and ���^���NOrg
OtherOrg= OtherOrg and ���R���x�A����Org
OtherOrg= OtherOrg and ���o������Org
OtherOrg= OtherOrg and ���t�^���~���uBOrg
OtherOrg= OtherOrg and not(PH21_�ނ炵�@�o���Z���T)
'===================================================================================================================
OtherStep= �Z�Ѓ^���NA���j�b�gstep
OtherStep= ORA(OtherStep,�Z�Ѓ^���NB���j�b�gstep)
OtherStep= ORA(OtherStep,�v�����j�b�gstep)
OtherStep= ORA(OtherStep,�Ȃ炵���ustep)
OtherStep= ORA(OtherStep,�W�킹���j�b�gstep)
OtherStep= ORA(OtherStep,�W��胆�j�b�gstep)
OtherStep= ORA(OtherStep,���͂񌟒mstep)
OtherStep= ORA(OtherStep,�o�L���[�����j�b�gstep)
OtherStep= ORA(OtherStep,�ق����@A���j�b�gstep)
OtherStep= ORA(OtherStep,�ق����@B���j�b�gstep)
OtherStep= ORA(OtherStep,�����R���x�AAstep)
OtherStep= ORA(OtherStep,�����R���x�ABstep)
OtherStep= ORA(OtherStep,�����R���x�ACstep)
OtherStep= ORA(OtherStep,������R���x�Astep)
'OtherStep= ORA(OtherStep,�ނ炵�@������R���x�Astep)
OtherStep= ORA(OtherStep,�����R���x�ADstep)
OtherStep= ORA(OtherStep,�����R���x�AEstep)
OtherStep= ORA(OtherStep,�����R���x�AFstep)
OtherStep= ORA(OtherStep,���������t�gstep)
OtherStep= ORA(OtherStep,����������step)
OtherStep= ORA(OtherStep,��򃆃j�b�gstep)
'OtherStep= ORA(OtherStep,���^���Nstep)
OtherStep= ORA(OtherStep,���R���x�A����step)
OtherStep= ORA(OtherStep,���o������step)
OtherStep= ORA(OtherStep,���t�^���~���uBstep)
'===================================================================================================================
OtherOrgErrStep=�Z�Ѓ^���NA���j�b�gErrStep
OtherOrgErrStep= ORA(OtherOrgErrStep,�Z�Ѓ^���NB���j�b�gErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�v�����j�b�gErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�Ȃ炵���uErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�W�킹���j�b�gErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�W��胆�j�b�gErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,���͂񌟒mErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�o�L���[�����j�b�gErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�ق����@A���j�b�gErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�ق����@B���j�b�gErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�����R���x�AAErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�����R���x�ABErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�����R���x�ACErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,������R���x�AErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�ނ炵�@������R���x�AErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�����R���x�ADErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�����R���x�AEErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�����R���x�AFErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,���������t�gErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,����������ErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,��򃆃j�b�gErrStep)
'OtherOrgErrStep= ORA(OtherOrgErrStep,���^���NErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,���R���x�A����ErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,���o������ErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,���t�^���~���uBErrStep)
'===================================================================================================================
OtherErrStep=�Z�Ѓ^���NA���j�b�gErrStep
OtherErrStep= ORA(OtherErrStep,�Z�Ѓ^���NB���j�b�gErrStep)
OtherErrStep= ORA(OtherErrStep,�v�����j�b�gErrStep)
OtherErrStep= ORA(OtherErrStep,�Ȃ炵���uErrStep)
OtherErrStep= ORA(OtherErrStep,�W�킹���j�b�gErrStep)
OtherErrStep= ORA(OtherErrStep,�W��胆�j�b�gErrStep)
OtherErrStep= ORA(OtherErrStep,���͂񌟒mErrStep)
OtherErrStep= ORA(OtherErrStep,�o�L���[�����j�b�gErrStep)
OtherErrStep= ORA(OtherErrStep,�ق����@A���j�b�gErrStep)
OtherErrStep= ORA(OtherErrStep,�ق����@B���j�b�gErrStep)
OtherErrStep= ORA(OtherErrStep,�����R���x�AAErrStep)
OtherErrStep= ORA(OtherErrStep,�����R���x�ABErrStep)
OtherErrStep= ORA(OtherErrStep,�����R���x�ACErrStep)
OtherErrStep= ORA(OtherErrStep,������R���x�AErrStep)
OtherErrStep= ORA(OtherErrStep,�ނ炵�@������R���x�AErrStep)
OtherErrStep= ORA(OtherErrStep,�����R���x�ADErrStep)
OtherErrStep= ORA(OtherErrStep,�����R���x�AEErrStep)
OtherErrStep= ORA(OtherErrStep,�����R���x�AFErrStep)
OtherErrStep= ORA(OtherErrStep,���������t�gErrStep)
OtherErrStep= ORA(OtherErrStep,����������ErrStep)
OtherErrStep= ORA(OtherErrStep,��򃆃j�b�gErrStep)
'OtherErrStep= ORA(OtherErrStep,���^���NErrStep)
OtherErrStep= ORA(OtherErrStep,���R���x�A����ErrStep)
OtherErrStep= ORA(OtherErrStep,���o������ErrStep)
OtherErrStep= ORA(OtherErrStep,���t�^���~���uBErrStep)
'===================================================================================================================
OtherEmgStep=�Z�Ѓ^���NA���j�b�gEmgStep
OtherEmgStep= ORA(OtherEmgStep,�Z�Ѓ^���NB���j�b�gEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�v�����j�b�gEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�Ȃ炵���uEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�W�킹���j�b�gEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�W��胆�j�b�gEmgStep)
OtherEmgStep= ORA(OtherEmgStep,���͂񌟒mEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�o�L���[�����j�b�gEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�ق����@A���j�b�gEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�ق����@B���j�b�gEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�����R���x�AAEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�����R���x�ABEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�����R���x�ACEmgStep)
OtherEmgStep= ORA(OtherEmgStep,������R���x�AEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�ނ炵�@������R���x�AEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�����R���x�ADEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�����R���x�AEEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�����R���x�AFEmgStep)
OtherEmgStep= ORA(OtherEmgStep,���������t�gEmgStep)
OtherEmgStep= ORA(OtherEmgStep,����������EmgStep)
OtherEmgStep= ORA(OtherEmgStep,��򃆃j�b�gEmgStep)
'OtherEmgStep= ORA(OtherEmgStep,���^���NEmgStep)
OtherEmgStep= ORA(OtherEmgStep,���R���x�A����EmgStep)
OtherEmgStep= ORA(OtherEmgStep,���o������EmgStep)
OtherEmgStep= ORA(OtherEmgStep,���t�^���~���uBEmgStep)
'==================================================================================================================
'�y  �f�o�C�X�ւ̋��d  �z


'	if �O�����H��AutoRun or �Z�Ѓ^���NA���j�b�gAutoRun or �Z�Ѓ^���NB���j�b�gAutoRun then
'		RLY5_�p�h���Z���T�d��=ON
'	else
'		RLY5_�p�h���Z���T�d��=OFF
'	end if

	mMC1_�C���o�[�^�p�d��=ON

	'RLY_�������d��OFF=ON

'===================================================================================================================
'�y ���������� �z
if CR2008 then

    ��������AutoMode=OFF
    ��������OrgErr=OFF
    ��������Err=OFF
    ��������Emg=OFF
    ��������step=0
    ��������ErrStep=0
    ��������OrgErrStep=0
    ��������EmgStep=0
	
	OtherEmgStep=0
	OtherErrStep=0
	OtherOrgErr=0
	
	���������蓮����step=0
	�ނ炵�����蓮����step=0
	���@�蓮����step=0
	
end if

'===================================================================================================================
'�y �ً}��~ �z
if ��������Emg  then
	��������EmgStep=1
end if

'===================================================================================================================


'===================================================================================================================
'  �R�}���h����
'===================================================================================================================
' ���������R�}���h����
'
if �������֎~ then
		����������AutoRun=OFF
		��򃆃j�b�gAutoRun=OFF
		���^���NAutoRun=OFF
		���R���x�A����AutoRun=OFF
		���o������AutoRun=OFF				
		���t�^���~���uBAutoRun=OFF
end if


if ��������EmgStep=0 and OtherEmgStep=0 then  

	if ��������ErrStep=0  and OtherErrStep=0 then
	
		if not(��������OrgErr) and not(OtherOrgErr) then

			if not(PB23_������~) or not(PB35_��~) or not(PB17_������~)  or ����������~ or ldp(������~) then
			
				��������AutoRun=OFF

				�Z�Ѓ^���NA���j�b�gAutoRun=OFF
				�Z�Ѓ^���NB���j�b�gAutoRun=OFF
				�v�����j�b�gAutoRun=OFF
				�Ȃ炵���uAutoRun=OFF
				�W�킹���j�b�gAutoRun=OFF
				�W��胆�j�b�gAutoRun=OFF
				���͂񌟒mAutoRun=OFF
				�o�L���[�����j�b�gAutoRun=OFF
				�ق����@A���j�b�gAutoRun=OFF
				�ق����@B���j�b�gAutoRun=OFF
				�����R���x�AAAutoRun=OFF
				�����R���x�ABAutoRun=OFF
				�����R���x�ACAutoRun=OFF
				������R���x�AAutoRun=OFF
				�ނ炵�@������R���x�AAutoRun=OFF
				�����R���x�ADAutoRun=OFF
				�����R���x�AEAutoRun=OFF
				�����R���x�AFAutoRun=OFF
				���������t�gAutoMode=OFF
				����������AutoRun=OFF
				��򃆃j�b�gAutoRun=OFF
				���^���NAutoRun=OFF
				���R���x�A����AutoRun=OFF
				���o������AutoRun=OFF				
				���t�^���~���uBAutoRun=OFF

			else
				'-------------------------------------------------------------------------------------
				'���C��              �ނ炵                  ���@
				'SSW3_�������[�h     SSW1_2_�^�]�؊��i�A���j SEL2_2_�^�]�؊��i�A���j
				'-------------------------------------------------------------------------------------
				' �������� ���� - �蓮  (2�X�e�b�v�؂�ւ��j
				'���C������{�b�N�X�� SSW3_�蓮���[�h  SSW3_�������[�h
				if 	not(���������蓮�ؑ֍ς�) and SSW3_�蓮���[�h and  not(SSW3_�������[�h) then
				
					select case ���������蓮����step
					case 0
						���������蓮�v��=ON
						inc(���������蓮����step)
					case 1
						if ���������蓮���� then

							��������AutoMode=OFF
					
							'----- �O�����H�����O�� --------
							'�O�����H��AutoMode=OFF
							'�O�����H��AutoRun=OFF
							'�v��AutoRun=OFF
							
							'if �����^�]���[�h and (�v��step<>0 or ����step<>0) then
							'	�����^�]���[�hEndWait=ON
							'end if
							'�����^�]���[�h=OFF
							
							'if �\��^�]���[�h and (�v��step<>0 or ����step<>0) then
							'	�\��^�]���[�hEndWait=ON
							'end if
							'�\��^�]���[�h=OFF

							inc(���������蓮����step)
						else if ���������蓮�֎~ then
							��������AutoMode=ON
							inc(���������蓮����step)
						end if
					case 2
						���������蓮�v��=OFF
						inc(���������蓮����step)
					case 3
						���������蓮�ؑ֍ς�=ON
						inc(���������蓮����step)
						'���������蓮����step=0
						
					end select
				
				else if SSW3_�������[�h and not(SSW3_�蓮���[�h) then
					���������蓮�ؑ֍ς�=OFF
					���������蓮����step=0
					���������蓮�v��=OFF
					��������AutoMode=ON
				end if

				'-------------------------------------------------------------------------------------
				' �g�p���Ȃ� 2019/7/ �ނ炵�@  ���� - �蓮 (2�X�e�b�v�؂�ւ��j 
				if 0 then '-- �g�p���Ȃ�
		
				if  not(��������AutoMode) then 'and  SSW1_1_�^�]�؊��i�P���j and not(SSW1_2_�^�]�؊��i�A���j) then
		
					�ނ炵�@������R���x�AAutoMode=OFF

				else 'if ��������AutoMode and SSW1_2_�^�]�؊��i�A���j and not(SSW1_1_�^�]�؊��i�P���j) then
					
					�ނ炵�@������R���x�AAutoMode=ON
				
				end if
				

				'-------------------------------------------------------------------------------------
				' �g�p���Ȃ� 2017/07 ���@ ���� - �蓮  (2�X�e�b�v�؂�ւ��j
				
				if not(��������AutoMode) then 'and SEL2_1_�^�]�؊��i�P���j and not(SEL2_2_�^�]�؊��i�A���j) then
				
				 	���R���x�A����AutoMode=OFF
					��򃆃j�b�gAutoMode=OFF
					���^���NAutoMode=OFF
				
				else 'if SEL2_2_�^�]�؊��i�A���j and not(SEL2_1_�^�]�؊��i�P���j) then

				 	���R���x�A����AutoMode=ON
					��򃆃j�b�gAutoMode=ON
					���^���NAutoMode=ON

				end if
		
				end if '-- �g�p���Ȃ�
				'-------------------------------------------------------------------------------------
				' �N��
				if ��������AutoMode and OtherStep=0 then
					if ldp(PB22_�����^�]) and (�^�]������ or �z�đҋ@�� or �^�]�������� or �e�X�g�^�]) and not(OtherOrg)  then
					
						�Z�Ѓ^���NA���j�b�gOrgErr=not(�Z�Ѓ^���NA���j�b�gOrg)
						�Z�Ѓ^���NB���j�b�gOrgErr=not(�Z�Ѓ^���NB���j�b�gOrg)
						�v�����j�b�gOrgErr=not(�v�����j�b�gOrg)
						�Ȃ炵���uOrgErr=not(�Ȃ炵���uOrg)
						�W�킹���j�b�gOrgErr=not(�W�킹���j�b�gOrg)
						�W��胆�j�b�gOrgErr=not(�W��胆�j�b�gOrg)
						���͂񌟒mOrgErr=not(���͂񌟒mOrg)
						�o�L���[�����j�b�gOrgErr=not(�o�L���[�����j�b�gOrg)
						�ق����@A���j�b�gOrgErr=not(�ق����@A���j�b�gOrg)
						�ق����@B���j�b�gOrgErr=not(�ق����@B���j�b�gOrg)
						�����R���x�AAOrgErr=not(�����R���x�AAOrg)
						�����R���x�ABOrgErr=not(�����R���x�ABOrg)
						�����R���x�ACOrgErr=not(�����R���x�ACOrg)
						������R���x�AOrgErr=not(������R���x�AOrg)
						�ނ炵�@������R���x�AOrgErr=not(�ނ炵�@������R���x�AOrg)
						�����R���x�ADOrgErr=not(�����R���x�ADOrg)
						�����R���x�AEOrgErr=not(�����R���x�AEOrg)
						�����R���x�AFOrgErr=not(�����R���x�AFOrg)
						���������t�gOrgErr=not(���������t�gOrg)
						����������OrgErr=not(����������Org)
						��򃆃j�b�gOrgErr=not(��򃆃j�b�gOrg)
						'���^���NOrgErr=not(���^���NOrg)
						���R���x�A����OrgErr=not(���R���x�A����Org)
						���o������OrgErr=not(���o������Org)
						���t�^���~���uBOrgErr=not(���t�^���~���uBOrg)
						�ނ炵�o��OrgErr=PH21_�ނ炵�@�o���Z���T
						
					end if
				end if
				
				if ��������AutoMode and OtherOrg and OtherStep=0 and not(PH21_�ނ炵�@�o���Z���T) then
					if ldp(PB22_�����^�]) and (�^�]������ or �z�đҋ@�� or �^�]�������� or �e�X�g�^�] ) then
						
						��������AutoRun=ON
						
						'------------------------------------------------------
						�Z�Ѓ^���NA���j�b�gAutoRun=ON
						�Z�Ѓ^���NB���j�b�gAutoRun=ON
						�v�����j�b�gAutoRun=ON
						�Ȃ炵���uAutoRun=ON
						�W�킹���j�b�gAutoRun=ON
						�W��胆�j�b�gAutoRun=ON
						���͂񌟒mAutoRun=ON
						�o�L���[�����j�b�gAutoRun=ON
						�ق����@A���j�b�gAutoRun=ON
						�ق����@B���j�b�gAutoRun=ON
						�����R���x�AAAutoRun=ON
						�����R���x�ABAutoRun=ON
						�����R���x�ACAutoRun=ON
						������R���x�AAutoRun=ON
						'�ނ炵�@������R���x�AAutoRun=ON
						�����R���x�ADAutoRun=ON
						�����R���x�AEAutoRun=ON
						�����R���x�AFAutoRun=ON
						���������t�gAutoRun=ON
						if not(�������֎~) then
							����������AutoRun=ON
							��򃆃j�b�gAutoRun=ON
							���^���NAutoRun=ON
							���R���x�A����AutoRun=ON
							���o������AutoRun=ON
							���t�^���~���uBAutoRun=ON
						else
							����������AutoRun=OFF
							��򃆃j�b�gAutoRun=OFF
							���^���NAutoRun=OFF
							���R���x�A����AutoRun=OFF
							���o������AutoRun=OFF
							���t�^���~���uBAutoRun=OFF
						end if
						'------------------------------------------------------
						�Z�Ѓ^���NA���j�b�gstep=1
						�Z�Ѓ^���NB���j�b�gstep=1
						�v�����j�b�gstep=1
						�Ȃ炵���ustep=1
						�W�킹���j�b�gstep=1
						�W��胆�j�b�gstep=1
						���͂񌟒mstep=1
						�o�L���[�����j�b�gstep=1
						�ق����@A���j�b�gstep=1
						�ق����@B���j�b�gstep=1
						�����R���x�AAstep=1
						�����R���x�ABstep=1
						�����R���x�ACstep=1
						������R���x�Astep=1
						'�ނ炵�@������R���x�Astep=1
						�����R���x�ADstep=1
						�����R���x�AEstep=1
						�����R���x�AFstep=1
						����������step=1
						���������t�gstep=1
						
						if not(�������֎~) then
							��򃆃j�b�gstep=1
							���^���Nstep=1
							���R���x�A����step=1
							���o������step=1
							���t�^���~���uBstep=1	
						else 
							��򃆃j�b�gstep=0
							���^���Nstep=0
							���R���x�A����step=0
							���o������step=0
							���t�^���~���uBstep=0	
						end if
						
						'------------------------------------------------------
						�����R���x�AA�r�o�v��=OFF
						�����R���x�AB�r�o�v��=OFF
						�����R���x�AC�r�o�v��=OFF
						�����R���x�AD�r�o�v��=OFF
						�����R���x�AE�r�o�v��=OFF
						�����R���x�AF�r�o�v��=OFF
						�����������r�o�v��=OFF
						���������t�g�r�o�v��=OFF
						���R���x�A�����r�o�v��=OFF
						���o�������r�o�v��=OFF
						���t�^���~B�r�o�v��=OFF						
						������R���x�A�r�o�v��=OFF						
						'------------------------------------------------------						
						�����R���x�AA���쒆=OFF
						�����R���x�AB���쒆=OFF
						�����R���x�AC���쒆=OFF
						������R���x�A���쒆=OFF
						�ނ炵�@������R���x�A���쒆=OFF
						�����R���x�AD���쒆=OFF
						�����R���x�AE���쒆=OFF
						�����R���x�AF���쒆=OFF
						���t�^���~���uA���쒆=OFF
						�����]�������쒆=OFF
						���������t�g���쒆=OFF
						�������������쒆=OFF
						��򃆃j�b�g���쒆=OFF
						���^���N���쒆=OFF
						���R���x�A�������쒆=OFF
						���o���������쒆=OFF
						���t�^���~���uB���쒆=OFF
						'------------------------------------------------------						
						
					end if	
				end if				
				'-------------------------------------------------------------------------------------
				
			end if


	'==================================================================================================================
	'�y ���_�ُ� �z
	
	
		else
			���������蓮�ؑ֍ς�=OFF
			���������蓮����step=0
			���������蓮�v��=OFF
		
			if ResetFlg then

				�Z�Ѓ^���NA���j�b�gOrgErr=OFF
				�Z�Ѓ^���NB���j�b�gOrgErr=OFF
				�v�����j�b�gOrgErr=OFF
				�Ȃ炵���uOrgErr=OFF
				�W�킹���j�b�gOrgErr=OFF
				�W��胆�j�b�gOrgErr=OFF
				���͂񌟒mOrgErr=OFF
				�o�L���[�����j�b�gOrgErr=OFF
				�ق����@A���j�b�gOrgErr=OFF
				�ق����@B���j�b�gOrgErr=OFF
				�����R���x�AAOrgErr=OFF
				�����R���x�ABOrgErr=OFF
				�����R���x�ACOrgErr=OFF
				������R���x�AOrgErr=OFF
				�ނ炵�@������R���x�AOrgErr=OFF
				�����R���x�ADOrgErr=OFF
				�����R���x�AEOrgErr=OFF
				�����R���x�AFOrgErr=OFF
				���������t�gOrgErr=OFF
				����������OrgErr=OFF
				��򃆃j�b�gOrgErr=OFF
				'���^���NOrgErr=OFF
				���R���x�A����OrgErr=OFF
				���o������OrgErr=OFF
				���t�^���~���uBOrgErr=OFF
				�ނ炵�o��OrgErr=OFF
				
				OtherOrgErr=OFF

			end if
			
		end if
	'==================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
			���������蓮�ؑ֍ς�=OFF
			���������蓮����step=0
			���������蓮�v��=OFF

			��������AutoRun=OFF

			�Z�Ѓ^���NA���j�b�gAutoRun=OFF
			�Z�Ѓ^���NB���j�b�gAutoRun=OFF
			�v�����j�b�gAutoRun=OFF
			�Ȃ炵���uAutoRun=OFF
			�W�킹���j�b�gAutoRun=OFF
			�W��胆�j�b�gAutoRun=OFF
			���͂񌟒mAutoRun=OFF
			�o�L���[�����j�b�gAutoRun=OFF
			�ق����@A���j�b�gAutoRun=OFF
			�ق����@B���j�b�gAutoRun=OFF
			�����R���x�AAAutoRun=OFF
			�����R���x�ABAutoRun=OFF
			�����R���x�ACAutoRun=OFF
			������R���x�AAutoRun=OFF
			�ނ炵�@������R���x�AAutoRun=OFF
			�����R���x�ADAutoRun=OFF
			�����R���x�AEAutoRun=OFF
			�����R���x�AFAutoRun=OFF
			���������t�gAutoRun=OFF
			����������AutoRun=OFF
			��򃆃j�b�gAutoRun=OFF
			���^���NAutoRun=OFF
			���R���x�A����AutoRun=OFF
			���o������AutoRun=OFF			
			���t�^���~���uBAutoRun=OFF
		

		select case ��������ErrStep
		case 0
		
		case 1
			�p�g���C�g��=ON

			if PB34_���Z�b�g or PB24_���Z�b�g or PB6_���Z�b�g then
				
				�p�g���C�g��=OFF
			
				almRLY_�d���m�F�[�Č�=OFF
				almRLY_�Z�Гd���m�F=OFF
				almRLY_�����R���x�AB�d���m�F=OFF
				almRLY_�ނ炵�d���m�F=OFF
				almRLY12_�d���m�F�����[=OFF
				alm�d���m�F�����[_A=OFF
				alm�d���m�F�����[_B=OFF
				almINV4_�R���x�A�d���m�F=OFF
			
				almPS1_�G�A�[����=OFF
				almPS2_�G�A�[����=OFF
				almPS3_�G�A�[����=OFF
			
				almTHR4_���ă|���v=OFF
				almTHR5_���ĉH��=OFF
				almTHR1_�����p���~�@���[�^=OFF
				almTHR2_�r�o�p���~�@���[�^=OFF
				almTHR3_�v�ʋ@���[�^=OFF
				almTHR6_�������[�^=OFF
				almTHR7_�������[�^=OFF
				almTHR8_�������[�^=OFF
				almTHR12_�������[�^=OFF
				almTHR13_�������[�^=OFF
				almTHR14_�������[�^=OFF
				almTHR15_�������[�^=OFF
				almTHR34_������R���x�A=OFF
				almTHR43_��ڃR���x�A=OFF
				almTHR18_������R���x�A=OFF
				almTHR17_�ނ炵�@���[�^=OFF
				almCSR1_�V���b�N�����[=OFF
				almTHR19_�������[�^=OFF
				almTHR20_�������[�^=OFF
				almTHR21_�������[�^=OFF
				almTHR22_�������[�^=OFF
				almTHR24_�z���|���v=OFF
				almTHR25_�������[�^=OFF
				almTHR26_�������[�^=OFF
				almTHR28_�������[�^=OFF
				almTHR29_�������[�^=OFF
				almTHR30_�������[�^=OFF
				almTHR31_���]���[�^=OFF
				almTHR10_���]���[�^=OFF
				
				almINV1_�R���x�A�ُ�=OFF
				almINV2_�R���x�A�ُ�=OFF
				almINV3_�R���x�A�ُ�=OFF
				almINV4_�R���x�A�ُ�=OFF
				
				�C���o�[�^1���Z�b�g=ON
				�C���o�[�^2���Z�b�g=ON
				�C���o�[�^3���Z�b�g=ON
				�C���o�[�^4���Z�b�g=ON

				
				almPH51_�t�^���m=OFF
				almPH2_�t�^���m=OFF
				almPH4_�t�^���m=OFF
				almPH53_�t�^���m=OFF
				almPH6_�t�^���m=OFF
				almPH12_�t�^���m=OFF
				almPH14_�t�^���m=OFF
				almPH16_�t�^���m=OFF
				almPH18_�t�^���m=OFF
				almPH20_�t�^���m=OFF
				almPH24_�t�^���m=OFF
				almPH26_�t�^���m=OFF
				almPH28_�t�^���m=OFF
				almPH30_�t�^���m=OFF
				almPH33_�t�^���m=OFF
				almPH35_�t�^���m=OFF
				almPH37_�t�^���m=OFF
				almPH49_�t�^���m=OFF
				almPH42_�t�^���m=OFF
				almPH44_�t�^���m=OFF
				almPH46_�t�^���m=OFF
				almPH8_�t�^���m=OFF
				almPH10_�t�^���m=OFF
				almPH40_�t�^���m=OFF

				inc(��������ErrStep)

			end if

		case 2
			if OtherErrStep=0 then
				��������ErrStep=0
			end if
			
		end select

	end if
	
	'==================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	���������蓮�ؑ֍ς�=OFF
	���������蓮����step=0
	���������蓮�v��=OFF
	
	
	select case ��������EmgStep
	case 0
	case 1
		'����~����
		ESPBL1_����~=CR2006
		PBL22_�����^�]=OFF
		page����~�\��=ON

		inc(��������EmgStep)
	case 2
		ESPBL1_����~=CR2006

		if PB34_���Z�b�g or PB24_���Z�b�g or PB6_���Z�b�g then
			almESPB5_����~=OFF
			almESPB1_����~=OFF
			almESPB2_����~=OFF
			almESPB3_����~IN=OFF
			almESPB4_����~IN=OFF
			almPB26_�R���x�A��~=OFF
			almPB27_�R���x�A��~=OFF
			almPB28_�R���x�A��~=OFF
			almPB29_�R���x�A��~=OFF

			ESPBL1_����~=OFF
			inc(��������EmgStep)
		end if

	case 3

		page����~�\��=OFF
		ESPBL1_����~=OFF
		PBL22_�����^�]=CR2006
		if ldp(PB22_�����^�]) then
			StartFlg=ON
			��������AutoRun=OFF
			inc(��������EmgStep)
		end if		

	case 4
		PBL22_�����^�]=OFF
		EmgFlg=OFF	
		inc(��������EmgStep)
		
	case 5	
		if �O�����H��EmgStep=0 and  OtherEmgStep=0 and not(PB22_�����^�]) then
			StartFlg=OFF
			��������ErrStep=0
			��������EmgStep=0
		end if
		
	end select

end if
