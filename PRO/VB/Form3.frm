VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3015
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   4560
   LinkTopic       =   "Form1"
   ScaleHeight     =   3015
   ScaleWidth      =   4560
   StartUpPosition =   3  '����ȱʡ
   Begin VB.CommandButton Command2 
      Caption         =   "CLEAR"
      Height          =   495
      Left            =   2400
      TabIndex        =   5
      Top             =   1800
      Width           =   1335
   End
   Begin VB.CommandButton Command1 
      Caption         =   "����"
      Height          =   495
      Left            =   720
      TabIndex        =   4
      Top             =   1800
      Width           =   1335
   End
   Begin VB.TextBox Text1 
      Height          =   615
      Index           =   1
      Left            =   2400
      MultiLine       =   -1  'True
      TabIndex        =   1
      Text            =   "Form3.frx":0000
      Top             =   720
      Width           =   1335
   End
   Begin VB.TextBox Text1 
      Height          =   615
      Index           =   0
      Left            =   720
      TabIndex        =   0
      Text            =   "Text1"
      Top             =   720
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   "�弶��"
      Height          =   495
      Index           =   1
      Left            =   2400
      TabIndex        =   3
      Top             =   240
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   " �ٷ���"
      Height          =   495
      Index           =   0
      Left            =   720
      TabIndex        =   2
      Top             =   240
      Width           =   1335
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()

Text1(1).Text = result(Val(Text1(0).Text))

End Sub

Private Sub Command2_Click()

Call clear

End Sub

Private Sub Form_Load()
 
Call clear
 
End Sub

Public Sub clear()

Text1(0) = ""
Text1(1) = ""

End Sub

Public Function result(score As Double) As String

Select Case score

Case Is > 100
result = "����������������������"

Case Is < 0
result = "����������������������"

Case Is >= 90
result = "����"

Case Is >= 80
result = "����"

Case Is >= 70
result = "�е�"

Case Is >= 60
result = "����"

Case Else
result = "������"

End Select

End Function

