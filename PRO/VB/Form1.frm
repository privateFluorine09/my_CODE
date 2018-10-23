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
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox Text4 
      Height          =   375
      Left            =   3000
      TabIndex        =   12
      Text            =   "Text4"
      Top             =   480
      Width           =   855
   End
   Begin VB.TextBox Text3 
      Height          =   375
      Left            =   2400
      TabIndex        =   10
      Text            =   "Text3"
      Top             =   2040
      Width           =   1695
   End
   Begin VB.CommandButton Command5 
      Caption         =   "CLEAR"
      Height          =   375
      Left            =   840
      TabIndex        =   9
      Top             =   2040
      Width           =   975
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   1440
      TabIndex        =   5
      Text            =   "Text2"
      Top             =   480
      Width           =   855
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   240
      TabIndex        =   4
      Text            =   "Text1"
      Top             =   480
      Width           =   855
   End
   Begin VB.CommandButton Command4 
      Caption         =   "/"
      Height          =   375
      Left            =   3360
      TabIndex        =   3
      Top             =   1200
      Width           =   615
   End
   Begin VB.CommandButton Command3 
      Caption         =   "*"
      Height          =   375
      Left            =   2520
      TabIndex        =   2
      Top             =   1200
      Width           =   615
   End
   Begin VB.CommandButton Command2 
      Caption         =   "-"
      Height          =   375
      Left            =   833
      TabIndex        =   1
      Top             =   1200
      Width           =   615
   End
   Begin VB.CommandButton Command1 
      Caption         =   "+"
      Height          =   375
      Left            =   1673
      TabIndex        =   0
      Top             =   1200
      Width           =   615
   End
   Begin VB.Label Label5 
      Caption         =   "结果"
      Height          =   255
      Left            =   3000
      TabIndex        =   13
      Top             =   120
      Width           =   735
   End
   Begin VB.Label Label4 
      Caption         =   "生成算式"
      Height          =   375
      Left            =   2400
      TabIndex        =   11
      Top             =   1680
      Width           =   855
   End
   Begin VB.Label Label3 
      Caption         =   "数2"
      Height          =   375
      Left            =   1440
      TabIndex        =   8
      Top             =   120
      Width           =   735
   End
   Begin VB.Label Label2 
      Caption         =   "数1"
      Height          =   375
      Left            =   240
      TabIndex        =   7
      Top             =   120
      Width           =   735
   End
   Begin VB.Label Label1 
      Caption         =   "运算类型"
      Height          =   375
      Left            =   0
      TabIndex        =   6
      Top             =   1320
      Width           =   735
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()

Text4.Text = Str(Val(Text1.Text) + Val(Text2.Text))
Text3.Text = Text1.Text & "+" & Text2.Text & "=" & Text4.Text

End Sub

Private Sub Command2_Click()

Text4.Text = Str(Val(Text1.Text) - Val(Text2.Text))
Text3.Text = Text1.Text & "-" & Text2.Text & "=" & Text4.Text

End Sub

Private Sub Command3_Click()

Text4.Text = Str(Val(Text1.Text) * Val(Text2.Text))
Text3.Text = Text1.Text & "*" & Text2.Text & "=" & Text4.Text

End Sub

Private Sub Command4_Click()

Text4.Text = Str(Val(Text1.Text) / Val(Text2.Text))
Text3.Text = Text1.Text & "/" & Text2.Text & "=" & Text4.Text

End Sub

Private Sub Command5_Click()

Call clear

End Sub

Public Sub clear()

Text1.Text = ""
Text2.Text = ""
Text3.Text = ""
Text4.Text = ""

End Sub

Private Sub Form_Load()

Call clear

End Sub
