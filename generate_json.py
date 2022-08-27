from os import environ
import json
import sys

def appendRule():
    tbl_id = sys.argv[1]
    tmp_rule=""
    if tbl_id=="ingress::pdr_ingress_table_ul" :
        match = '''
        {
        "inner_ipv4.src_addr": { "value": "%s" },
        "scalars.metadata_t@intf": { "value": "%s" }
        }''' % (
            sys.argv[2], #inner src ip
            sys.argv[3]  #intf
        )
        action = '''
        {
            "data": {
                "far_id": { "value": "%s" },
                "must_decap": { "value": "%s" }
            },
            "type": "ingress::set_rules"
        }''' % (
            sys.argv[4], #far_id
            sys.argv[5]  # must_decap
        )
        rule_name = sys.argv[1] #inner_src_ip
        tmp_rule = '''
        {
            "action": %s,
            "name": "%s",
            "match": %s
        }''' % (
            action,
            rule_name,
            match
        )
    if tbl_id=="ingress::pdr_ingress_table_dl" :
        match = '''
        {
        "ipv4.dst_addr": { "value": "%s" },
        "scalars.metadata_t@intf": { "value": "%s" }
        }''' % (
            sys.argv[2], #inner src ip
            sys.argv[3]  #intf
        )
        action = '''
        {
            "data": {
                "far_id": { "value": "%s" },
                "must_decap": { "value": "%s" }
            },
            "type": "ingress::set_rules"
        }''' % (
            sys.argv[4], #far_id
            sys.argv[5]  # must_decap
        )
        rule_name = sys.argv[1] #inner_src_ip
        tmp_rule = '''
        {
            "action": %s,
            "name": "%s",
            "match": %s
        }''' % (
            action,
            rule_name,
            match
        )
    if tbl_id=="ingress::far_egress_table" :
        match = '''
        {
        "scalars.metadata_t@far_id": { "value": "%s" }
        }''' % (
            sys.argv[2], #inner src ip
        )
        action = '''
        {
            "data": {
                "teid": { "value": "%s" },
                "ran_ip": { "value": "%s" },
                "upf_ip": { "value": "%s" }
            }, 
            "type": "ingress::gtp_encap"}''' % (
            sys.argv[3], #teid
            sys.argv[4], #ran_ip
            sys.argv[5]  #upf_ip
        )
        rule_name = "fuck" #inner_src_ip
        tmp_rule = '''{"action": %s,"name": "%s","match": %s}''' % (
            action,
            rule_name,
            match
        )
    print(tmp_rule)
    tmp_rule = json.loads(tmp_rule)
    with open('/home/winlab/smartNIC/tmp.p4cfg') as read_json_file:
        tmp_json = json.load(read_json_file)
        tmp_json['tables'][tbl_id]['rules'].append(tmp_rule)
        with open('/home/winlab/smartNIC/tmp.p4cfg', 'w') as write_json_file:
            json.dump(tmp_json, write_json_file)
        
def main():

    if sys.argv[1] == "init":
        with open('/home/winlab/smartNIC/init-key.p4cfg') as read_json_file:
                tmp_json = json.load(read_json_file)
        with open('/home/winlab/smartNIC/tmp.p4cfg', 'w') as write_json_file:
                json.dump(tmp_json, write_json_file)
    else:
        appendRule()

if __name__ == '__main__':
    main()
    print('Bye!')
