import pandas as pd
import warnings
warnings.filterwarnings('ignore')
from xlsxwriter import Workbook


class ReportGenerator:
    def __init__(self, input_file, output_file):
        self.input_file = input_file
        self.output_file = output_file
        self.final_output_SGBD = '/home/jazib/PycharmProjects/Excel/Output/SGBD_New.xlsx'
        self.test_status_new = '/home/jazib/PycharmProjects/Excel/Output/Teststatus_New.xlsx'

    def generate_SGBD(self):
        input_dtcs = pd.read_excel(self.input_file, sheet_name='DTCs', header=1)
        input_jobs = pd.read_excel(self.input_file, sheet_name='JOBs', header=1)

        output_dtcs = pd.read_excel(self.output_file, sheet_name='DTCs')
        output_jobs = pd.read_excel(self.output_file, sheet_name='Jobs')

        columns_from_dtcs = ['Impl.-Status', 'Test-Status Lieferant', 'Test-Status Sublieferant']
        columns_from_jobs = ['Impl.-Status', 'Test-Status', 'Implementiert bis']

        for i in columns_from_dtcs:
            output_dtcs[i] = input_dtcs[i]

        for i in columns_from_jobs:
            output_jobs[i] = input_jobs[i]

        with pd.ExcelWriter(self.final_output_SGBD, engine='xlsxwriter') as writer:
            output_dtcs.to_excel(writer, sheet_name='DTCs', index=False, startrow=0)
            output_jobs.to_excel(writer, sheet_name='Jobs', index=False, startrow=0)

    def new_test_status(self):
        new_sgbd_dtcs = pd.read_excel(self.final_output_SGBD, sheet_name='DTCs')
        new_sgbd_jobs = pd.read_excel(self.final_output_SGBD, sheet_name='Jobs')

        

if __name__ == '__main__':
    test_status = '/home/jazib/PycharmProjects/Excel/Input/Teststatus.xlsx'
    sbgd = '/home/jazib/PycharmProjects/Excel/Input/SGBD.xlsx'

    dest = '/home/jazib/PycharmProjects/Excel/Output'

    x = ReportGenerator(test_status, sbgd)
    x.generate_SGBD()

    print('SUCCESS')
