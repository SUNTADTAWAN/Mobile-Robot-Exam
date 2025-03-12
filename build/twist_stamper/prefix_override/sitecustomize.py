import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/tadtawan/fra532_lecture5_ws/install/twist_stamper'
