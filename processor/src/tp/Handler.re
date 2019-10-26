
[@bs.deriving jsConverter]
type header = {
  batcherPublicKey: string,
  // dependencies: array(string),
  familyName: string,
  familyVersion: string,
  inputs: array(string),
  nonce: string,
  outputs: array(string),
  payloadSha512: string,
  signerPublicKey: string
};

// im pretty sure this can be modelled better..
class type _header = 
[@bs]{
  pub batcherPublicKey: string;
  pub familyName: string;
  pub familyVersion: string;
  pub inputs: array(string);
  pub nonce: string;
  pub outputs: array(string);
  pub payloadSha512: string;
  pub signerPublicKey: string;
};

class type _tpRequest =
  [@bs]
  {
    pub payload: Node.Buffer.t;
    pub header: Js.t(_header);
  };
type tpRequest = Js.t(_tpRequest);

type context;


// just for my context
let headerObj = [%raw"{ batcherPublicKey:
   '02037dd8a1039f5e6721ccfa29926846a60310e03a0cd665bfe7f05620d6f08a59',
  familyVersion: '1.0',
  familyName: 'xo',
  inputs:
   [ '5b73496ba2b9df31680dcda5a4a083c462109df7e1abf32ff25d82f8b3cbf9734de8ef' ],
  nonce: '0x1.76d1a8ea26e8dp+30',
  outputs:
   [ '5b73496ba2b9df31680dcda5a4a083c462109df7e1abf32ff25d82f8b3cbf9734de8ef' ],
  payloadSha512:
   '6b6e3e26a9e2e054d8d08ca87d59e01a07b81790b1c678d0fba0dba75965b7f06b9a6dff9bad0b2601957148d521c7be34b8b4e43d16b1d93bc997d21be4700f',
  signerPublicKey:
   '02037dd8a1039f5e6721ccfa29926846a60310e03a0cd665bfe7f05620d6f08a59' }"];

//Implementation for Js Wrapper SupplyHandler
module SupplyHandlerImpl = {
  open Payload;

  // let transactionFamilyName = "transactionFamilyName";
  // let versions = [|"versions"|];
  // let namespaces = [|"namespaces"|];


  // header : normal type
  // payload : buffer
  // context 

  let apply = (_t, transaction: tpRequest, context: context) => {

    let header = headerFromJs(transaction##header);
    let payload = determinePayload(transaction##payload);
    let state = context;

    Js.log2("CONTEXT//State", state );
    
    // validate_timestamp

    switch (payload) {
    | Some(data) =>
      switch (data.action) {
      | CreateAgent => Js.log("lol")
      | CreateRecord => Js.log("lol")
      | TransferRecord => Js.log("lol")
      | UpdateRecord => Js.log("lol")
      | NotDefined => Js.log("action Not defined!")
      // Delete
      | Create => Js.log("Xo Create")
      // Delete
      | Take => Js.log("Xo Take")
      };

      ();
    | _ => Js.log("RAISE EXCETIPN!!")
    };
  };



  let createAgent = (state, pubKey:string, payload: payloadType) => {
    ();
  };

  let createRecord = (state, pubKey, payload: payloadType) => {
    ();
  };
  let transferRecord = (state, pubKey, payload: payloadType) => {
    ();
  };
  let updateRecord = (state, pubKey, payload: Payload.payloadType) => {
    ();
  };
};