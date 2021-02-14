object App: TApp
  Left = 0
  Top = 0
  Caption = 'Painter App'
  ClientHeight = 335
  ClientWidth = 538
  Color = clBtnFace
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnCreate = FormCreate
  OnResize = FormResize
  DesignSize = (
    538
    335)
  PixelsPerInch = 96
  TextHeight = 13
  object ImageEl: TImage
    Left = 10
    Top = 8
    Width = 401
    Height = 319
    Anchors = [akLeft, akTop, akRight, akBottom]
    Stretch = True
    OnMouseDown = ImageElMouseDown
    OnMouseMove = ImageElMouseMove
    OnMouseUp = ImageElMouseUp
  end
  object Figure: TRadioGroup
    Left = 417
    Top = 8
    Width = 112
    Height = 121
    Anchors = [akTop, akRight]
    Caption = 'Figure'
    ItemIndex = 0
    Items.Strings = (
      'Pen'
      'Line'
      'Circle'
      'Rect')
    TabOrder = 0
    OnClick = FigureClick
  end
  object Line: TRadioGroup
    Left = 418
    Top = 135
    Width = 112
    Height = 122
    Anchors = [akTop, akRight]
    Caption = 'Line'
    ItemIndex = 0
    Items.Strings = (
      'solid'
      'dashed'
      'dotted'
      'dash-dotted')
    TabOrder = 1
    OnClick = LineClick
  end
  object OpenButton: TButton
    Left = 417
    Top = 263
    Width = 49
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'Open'
    TabOrder = 2
    OnClick = OpenButtonClick
  end
  object SaveButton: TButton
    Left = 480
    Top = 263
    Width = 50
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'Save'
    TabOrder = 3
    OnClick = SaveButtonClick
  end
  object ClearButton: TButton
    Left = 417
    Top = 294
    Width = 113
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'Clear'
    TabOrder = 4
    OnClick = ClearButtonClick
  end
end
